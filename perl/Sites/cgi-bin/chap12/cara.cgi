#!/usr/bin/perl
#cara.cgi - Location header example
use CGI qw(:standard -debug);
use strict;

#declare and assign value to variable
my $name;
$name = param('Name');

#create Hello page
if ($name ne "") {
print "Content-type: text/html\n\n";
print "<HTML>\n";
print "<HEAD><TITLE>Cara Antiques</TITLE></HEAD>\n";
print "<BODY>\n";
print "<H1 ALIGN=center>Cara Antiques<HR>\n";
print "Hello, $name!</H1></BODY></HTML>";
}
else {print "Location: ../../public_html/chap12/cara2.html\n\n";}


