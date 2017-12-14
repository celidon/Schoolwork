#!/usr/bin/perl
#c02ex4.cgi - creates a dynamic Web page
print "Content-type: text/html\n\n";

use CGI qw(:standard -debug);

#create Web page
print "<HTML>\n";
print "<HEAD><TITLE>Jackson Elementary School</TITLE><BASEFONT SIZE=5></HEAD>\n";
print "<BODY>\n";
print "The Spanish word for ", param('eng')," is ", param('spn'),".\n";
print "</BODY>\n";
print "</HTML>\n";
