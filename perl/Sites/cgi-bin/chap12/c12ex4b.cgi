#!/usr/bin/perl
#./c12ex4b.cgi - 
print "Content-type: text/html\n\n";
use CGI qw(:standard -debug);
use strict;
my @err;
@err = param('Error');
#generate HTML
print "<HTML>\n";
print "<HEAD><TITLE>Error Page</TITLE></HEAD>\n";
print "<BODY>Error! Not all parts of the form are filled out. Please go back and complete:<BR>\n";
foreach (@err) {print "$_<BR>\n";}
print "</BODY>\n";
print "</HTML>\n";
