#!/usr/bin/perl
#c09ex4.cgi
print "Content-type: text/html\n\n";
use CGI qw(:standard -debug);

use SDBM_File;
use Fcntl;

use strict;

my($button,$account,$card,$valid);

$button=param('Button');
$card=param('Card');
$account=param('Number');

if ($button eq "Enter Data") {
	$valid=validate();
	if ($valid eq 'y') {add();}
	else {error();}
}
elsif ($button eq "Display Data") {view();}
exit;

#*****user-defined functions*****
sub validate {
	my $check='y';
	if ($card eq '' or $account eq '') {$check='n';}
	return $check;
}

sub strip {
	$card =~ tr/^ +//d;
	$card =~ tr/ +$//d;
	
	$account =~ tr/^ +//d;
	$account =~ tr/ +$//d;
}

sub add {
	strip();
	$card=uc $card;

	my %credit;
	my $msg;
	
	tie(%credit,"SDBM_File",'c09ex4',O_CREAT|O_RDWR,0666)
		or die "Error opening c09ex4. $!, stopped";
	if (exists($credit{$account})) {$msg = "Account $account already exists";}
	else {
		$credit{$account} = $card;
		$msg="The account number $account has been saved as a $card type credit card."
	}
	untie(%credit);

print <<endHTML;
<HTML><HEAD><TITLE>Credit Card Information</TITLE></HEAD>
<BODY>$msg</BODY></HTML>
endHTML
}

sub error {
print <<endHTML;
<HTML><HEAD><TITLE>Credit Card Information</TITLE></HEAD>
<BODY>Please return and complete all fields</BODY></HTML>
endHTML
}

sub view {
	my %credit;
	
	tie(%credit,"SDBM_File",'c09ex4',O_RDWR,0)
		or die "Error opening c09ex4. $!, stopped";

print <<endHTML;
<HTML><HEAD><TITLE>Credit Card Information</TITLE></HEAD>
<BODY>
<TABLE><TR><TD>Credit Card</TD><TD> </TD><TD>Account Number</TD></TR>
endHTML
foreach my $key (sort(keys(%credit))) {print "<TR><TD>$credit{$key}</TD><TD> </TD><TD>$key</TD></TR>\n";}
print "</TABLE></BODY></HTML>";

untie(%credit);
}
