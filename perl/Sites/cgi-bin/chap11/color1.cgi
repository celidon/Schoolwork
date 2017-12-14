#!/usr/bin/perl
#color1.cgi - first script
use CGI qw(:standard -debug);

#prevent Perl from creating undeclared variables
use strict;

#declare and assign value to variables
my $color;
$color = param('Color');

#create and send cookie

#create Web page
print "<HTML>\n";
print "<HEAD><TITLE>Maribeth Designs</TITLE></HEAD>\n";
print "<BODY BGCOLOR=>\n";
print "<FORM ACTION='../../cgi-bin/chap11/c11ex4b.cgi' METHOD=POST>\n";
print "<H1>Maribeth Designs</H1>\n";
print "<I>Welcome to our Web site!</I><BR><BR><BR>\n";
print "<INPUT TYPE=submit VALUE='Go to Next Page'>\n";
print "</FORM></BODY></HTML>\n";
