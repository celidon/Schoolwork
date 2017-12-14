#!/usr/bin/perl
#c11ex5.cgi - 
use CGI qw(:standard -debug);
use strict;
my ($count,$C_count);
$count=cookie("Count");
if ($count eq '') {$count = 1;}
else {$count+=1;}
$C_count=cookie(-name,"Count",-value,"$count+=1",-expires,"+6M",-path,"../../cgi-bin/chap11");
#generate HTML
print header(-cookie => $C_count);
print "<HTML>\n";
print "<HEAD><TITLE>Jubilee Book Club</TITLE></HEAD>\n";
print "<BODY>You have visited this site a total of: $count times</BODY>\n";
print "</HTML>\n";
