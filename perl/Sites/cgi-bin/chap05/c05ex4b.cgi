#!/usr/bin/perl
#c05ex4b.cgi
print "Content-type: text/html\n\n";
use CGI qw(:standard -debug);
use strict;

my($name,$serial,$mod,$sys,@records);

open(IN,'c05ex4.txt')
	or die "Error opening c05ex4.txt. $!, stopped";
@records=<IN>;
close(IN);
#generate HTML
print "<HTML>\n";
print "<HEAD><TITLE>Juniper Printers</TITLE></HEAD>\n";
print "<BODY>\n";
foreach my $rec(@records){
	chomp($rec);
	($name,$serial,$mod,$sys)=split(/\|/,$rec);
	print "$name\t $serial\t $mod\t $sys<BR>\n";
}
print "</BODY>\n";
print "</HTML>\n";
