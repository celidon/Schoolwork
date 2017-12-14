#!/usr/bin/perl
#c09ex5.cgi
print "Content-type: text/html\n\n";
use CGI qw(:standard -debug);

use SDBM_File;
use Fcntl;

use strict;

my($button,$code,$name,$valid,$price);

$button=param('Button');
$name=param('Name');
$code=param('Code');
$price=param('Price');

if ($button eq "Save") {
	$valid=validate();
	if ($valid eq 'y') {add();}
	else {error();}
}
elsif ($button eq "Delete") {remove();}
exit;

#*****user-defined functions*****
sub validate {
	my $check='y';
	if ($name eq '' or $code eq '' or $price eq '') {$check='n';}
	return $check;
}

sub strip {
	$name =~ tr/^ +//d;
	$name =~ tr/ +$//d;
	
	$code =~ tr/^ +//d;
	$code =~ tr/ +$//d;

	$price =~ tr/^ +//d;
	$price =~ tr/ +$//d;
	$price =~ tr/$,//d;
}

sub add {
	strip();
	$name=uc $name;
	$code=uc $code;

	my %candles;
	my $msg;
	
	tie(%candles,"SDBM_File",'c09ex5',O_CREAT|O_RDWR,0666)
		or die "Error opening c09ex5. $!, stopped";
	if (exists($candles{$code})) {$msg = "A product is already associated with that code.";}
	else {
		$candles{$code} = "$name,$price";
		$msg = "The code number $code has been saved $name candle at \$$price apiece";
	}
	untie(%candles);

print <<endHTML;
<HTML><HEAD><TITLE>Candles Unlimited</TITLE></HEAD>
<BODY>$msg</BODY></HTML>
endHTML
}

sub error {
print <<endHTML;
<HTML><HEAD><TITLE>Candles Unlimited</TITLE></HEAD>
<BODY>Please return and complete all fields</BODY></HTML>
endHTML
}

sub remove {
	strip();
	my %candles;
	my $msg;

	$code=uc $code;
	
	tie(%candles,"SDBM_File",'c09ex5',O_RDWR,0)
		or die "Error opening c09ex5. $!, stopped";
	if (exists($candles{$code})) {
		delete($candles{$code});
		$msg = "Product $code has been deleted";
	}
	else {$msg = "Product $code does not exist";}
	untie(%candles);
print <<endHTML;
<HTML><HEAD><TITLE>Candles Unlimited</TITLE></HEAD>
<BODY>$msg</BODY></HTML>
endHTML
}
