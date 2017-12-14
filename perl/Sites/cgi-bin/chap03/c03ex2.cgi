#!/usr/bin/perl
#c03ex2.cgi - calculates gross pay and creates a dynamic Web page
#that contains form data and the gross pay
print "Content-type: text/html\n\n";
use CGI qw(:standard -debug);

#prevent Perl from creating undeclared variables
use strict;
#declare variables
my ($employee, $hours, $rate, $pay);
#assign values to variables
$employee=param('Employee');
$hours=param('Hours');
$rate=param('Rate');

#calculate gross pay amount
$pay=$hours*$rate;

#create Web page
print "<HTML>\n";
print "<HEAD><TITLE>AeroDynamics</TITLE><BASEFONT SIZE=5></HEAD>\n";
print "<H1>Gross Pay Calculation</H1>\n";
print "<BODY>\n";
printf "Employee: $employee<BR>\n";
printf "Hours: %02d<BR>\n", $hours;
printf "Rate: \$%.2f<BR><BR>\n", $rate;
printf "Gross pay: \$%.2f\n", $pay;
print "</BODY>\n";
print "</HTML>\n";
