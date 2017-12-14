#!/usr/bin/perl
#c10ex3a.cgi - first script
print "Content-type: text/html\n\n";
use CGI qw(:standard -debug);

#prevent Perl from creating undeclared variables
use strict;

#declare and assign value to variable
my $col=param("Color");
#create Web page
print "<HTML>\n";
print "<HEAD><TITLE>Maribeth Designs</TITLE></HEAD>\n";
print "<BODY BGCOLOR=$col>\n";
print "<FORM ACTION='../../cgi-bin/chap10/c10ex3b.cgi' METHOD=GET>\n";
print "<H1>Maribeth Designs</H1>\n";
print "<I>Welcome to our Web site!</I><BR><BR><BR>\n";
print "<INPUT TYPE=submit VALUE='Go to Next Page'><INPUT TYPE=hidden NAME=H_col VALUE=$col>\n";
print "</FORM></BODY></HTML>\n";
