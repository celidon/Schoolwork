#!/usr/bin/perl
#c06ex2.cgi - calculates a bonus amount and creates a dynamic Web page
#that contains form data and a bonus amount
print "Content-type: text/html\n\n";
use CGI qw(:standard -debug);

#prevent Perl from creating undeclared variables
use strict;
#declare variables
my ($name, $sales, $rate, $bonus, @errors,$size);
#assign values to variables
$name = param('Salesperson');
$sales = param('Sales');
$rate = param('Rate');

if ($name eq "") { push(@errors,"Name field is empty");}
if ($sales eq "") { push(@errors,"Sales field is empty");}
if ($rate eq "") { push(@errors,"Rate field is empty");}
elsif ($rate > .10) { push(@errors,"Rate is too high");}
elsif ($rate < .05) { push(@errors,"Rate is too low");}
$size=@errors;
if ($size > 0) {
print "<HTML>\n<HEAD><TITLE>Patton Industries</TITLE></HEAD>\n";
print "<BODY>Error calculating bonus.<BR>\nPlease go back and correct the following errors:<BR><BR>\n";
for(my $x=0;$x<$size;$x+=1) {
	print "$errors[$x]<BR>\n";
}
print "</BODY></HTML>\n";
}
else{
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
