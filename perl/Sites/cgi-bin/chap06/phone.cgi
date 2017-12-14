#!/usr/bin/perl
#c06ex5.cgi - creates a dynamic Web page
print "Content-type: text/html\n\n";

use CGI qw(:standard -debug);
use strict;

#declare variables
my ($empnum, $ext);

#assign value to variable
$empnum=param("Empnum");
if($empnum>3 or $empnum<1){$ext="Error";}
elsif($empnum==1{$ext=1234;}
elsif($empnum==2{$ext=1122;}
else{$ext=3345;}
#create Web page
print "<HTML>\n";
print "<HEAD><TITLE>Thomas Manufacturing</TITLE></HEAD>\n";
print "<BODY><H2>Extension: \n";
print $ext;
print "</H2></BODY>\n";
print "</HTML>\n";
