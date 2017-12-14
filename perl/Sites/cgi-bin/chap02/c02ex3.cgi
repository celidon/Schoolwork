#!/usr/bin/perl
#c02ex3.cgi - creates a dynamic webpage
print "Content-type: text/html\n\n";
use CGI qw(:standard -debug);

#generate HTML
print "<HTML>\n";
print "<HEAD><TITLE>Jackson Elementary School</TITLE><BASEFONT SIZE=5></HEAD>\n";
print "<BODY>\n";
print "The capital of ", param('state'), " is ", param('cap'),".<BR>\n";
print param('state')," was the ", param('num')," to sign the US Constitution.\n";
print "</BODY>\n";
print "</HTML>\n";
