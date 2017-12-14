#!/usr/bin/perl
#c11ex2a.cgi - displays a sign-in form
print "Content-type: text/html\n\n";
use CGI qw(:standard -debug);

#prevent Perl from creating undeclared variables
use strict;

#declare variable
my ($name,$email);

#retrieve Name cookie
$name = cookie('Name');
$email = cookie('Email');

print "<HTML>\n";
print "<HEAD><TITLE>Jubilee Book Club</TITLE></HEAD>\n";
print "<BODY>\n";
print "<H1>Jubilee Book Club Sign-In Form</H1><HR>\n";
print "<FORM \n";
print "ACTION='../../cgi-bin/chap11/c11ex2b.cgi' \n"; 
print "METHOD=POST>\n";

print "<TABLE>\n";
print "<TR><TD>Name:</TD><TD>\n";
print "<INPUT TYPE=text NAME=Name SIZE=25 VALUE='$name'>\n";
print "</TD></TR>\n";
print "<TR><TD>Email:</TD><TD>\n";
print "<INPUT TYPE=text NAME=Email SIZE=50 VALUE='$email'>\n</TD></TR>\n";
print "</TABLE>\n";

print "<BR><INPUT TYPE=submit VALUE=Submit>\n";
print "</FORM></BODY></HTML>\n";

