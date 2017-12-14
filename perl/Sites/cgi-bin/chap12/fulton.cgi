#!/usr/bin/perl
#fulton.cgi - Refresh header example

print "Refresh: 3; URL=../../public_html/chap12/fulton2.html\n";
print "Content-type: text/html\n\n";

print "<HTML>\n";
print "<HEAD><TITLE>Fulton Enterprises</TITLE></HEAD>\n";
print "<BODY>\n";
print "<H2>The document you are requesting has moved.\n";
print "Please update your bookmark.\n";
print "</H2>\n";
print "<A HREF='../../public_html/chap12/fulton2.html'>\n";
print "Click here to be redirected to the document's new location</A>\n";
print "</BODY></HTML>\n";
