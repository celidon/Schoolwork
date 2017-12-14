#!/usr/bin/perl
#c12ex4a.cgi - calculates a bonus amount and creates a dynamic Web page
#that contains form data and a bonus amount
use CGI qw(:standard -debug);

#prevent Perl from creating undeclared variables
use strict;
#declare variables
my ($name, $sales, $rate, $bonus,$msg,@err);
#assign values to variables
$name = param('Salesperson');
$sales = param('Sales');
$rate = param('Rate');

($name,$sales,$rate) = strip();

if ($name ne '' and $sales ne '' and $rate ne '')
{
print "Content-type: text/html\n\n";

$rate=fixr();

#calculate bonus amount
$bonus = $sales * $rate;

#create Web page
print "<HTML>\n";
print "<HEAD><TITLE>Patton Industries</TITLE><BASEFONT SIZE=5></HEAD>\n";
print "<H1>Bonus Calculation</H1>\n";
print "<BODY>\n";
print "Salesperson: $name<BR>\n";
printf "Your bonus is \$%.2f.<BR><BR>\n", $bonus;
printf "You entered a sales amount of \$%.2f and a \n", $sales;
printf "bonus rate of %.1f%%.<BR>\n", $rate * 100;
print "</BODY>\n";
print "</HTML>\n";
}
else {
	if ($name eq '') {push(@err,"Error=Salesperson+name");}
	if ($sales eq '') {push(@err,"Error=Sales+amount");}
	if ($rate eq '') {push(@err,"Error=Bonus+rate");}
	$msg='';
	foreach (@err) {$msg = $msg.$_.'&';}
	print "Location: ../../cgi-bin/chap12/c12ex4b.cgi?$msg\n\n";
}
#*****user-defined functions*****

sub strip {
	my ($n,$s,$r)=($name,$sales,$rate);
	
	$n =~ tr/^ +//d;
	$n =~ tr/ +$//d;

	$s =~ tr/^ +//d;
	$s =~ tr/ +$//d;
	$s =~ tr/$,//d;

	$r =~ tr/^ +//d;
	$r =~ tr/ +$//d;

	return $n,$s,$r	
}
sub fixr {	
	my $r = $rate;

	if ( $r =~ m/%/ ) {$r =~ tr/%//;}
		
	my $index = index($r,".");
	if ( $index !=0 ) { 
			$r =~ tr/.//; 
			$r = $r/100;
	}
	else { $r = $r/100; }

	return $r	
}
