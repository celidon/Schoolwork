#!/usr/bin/perl
#c06ex4.cgi - creates a dynamic Web page
print "Content-type: text/html\n\n";

use CGI qw(:standard -debug);
use strict;

#declare variables
my ($dept);
my @dept_and_names = ("Accounting", "John Montgomery",
		      "Customer Service", "Carol Jefferson",
		      "Customer Service", "Jill Paulo",
		      "Research and Development", "Jeffrey Johnson",
		      "Accounting", "Sam Rantini",
		      "Payroll", "Susan Choi",
		      "Research and Development", "LaChonda Washington",
		      "Customer Service", "Nancy Smith");

#assign values to variables
$dept = param('Dept');

#create Web page
print "<HTML>\n";
print "<HEAD><TITLE>Berelli Company</TITLE></HEAD>\n";
print "<BODY><H2>$dept Department Employees</H2><BR>\n";
for (my $i=0;$i<scalar(@dept_and_names);$i+=1) {
	if($dept_and_names[$i] eq $dept) { print "$dept_and_names[$i+1]<BR>\n";}
}
print "</BODY>\n";
print "</HTML>\n";
