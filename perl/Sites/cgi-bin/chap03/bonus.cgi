#!/usr/bin/perl
#bonus.cgi - calculates a bonus amount and creates a dynamic Web page
#that contains form data and a bonus amount
print "Content-type: text/html\n\n";
use CGI qw(:standard -debug);

#prevent Perl from creating undeclared variables
use strict;
#declare variables
my ($name, $sales, $rate, $bonus);
#assign values to variables
$name = param('Salesperson');
$sales = param('Sales');
$rate = param('Rate');

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
