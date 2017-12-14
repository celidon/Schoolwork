#!/usr/bin/perl
#c12ex3.cgi - calculates a bonus amount and creates a dynamic Web page
#that contains form data and a bonus amount
use CGI qw(:standard -debug);

#prevent Perl from creating undeclared variables
use strict;
#declare variables
my ($name, $sales, $rate, $bonus);
#assign values to variables
$name = param('Salesperson');
$sales = param('Sales');
$rate = param('Rate');

if ($name ne '' and $sales ne '' and $rate ne '')
{
print "Content-type: text/html\n\n";


($name,$sales,$rate) = strip();

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
else {print "Location: ../../public_html/chap12/c12ex3b.html\n\n";}
#*****user-defined functions*****

sub strip {
	my ($n,$s,$r)=($name,$sales,$rate);
	
	$n =~ tr/^ +//;
	$n =~ tr/ +$//;

	$s =~ tr/^ +//;
	$s =~ tr/ +$//;
	$s =~ tr/$,//d;

	$r =~ tr/^ +//;
	$r =~ tr/ +$//;
	
	if ( $r =~ m/%/ ) {$r =~ tr/%//;}
		
	my $index = index($r,".");
	if ( $index !=0 ) { 
			$r =~ tr/.//; 
			$r = $r/100;
	}
	else { $r = $r/100; }

	return $n,$s,$r	
}
