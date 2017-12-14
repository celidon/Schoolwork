#!/usr/bin/perl
#c05ex5.cgi
print "Content-type: text/html\n\n";
use CGI qw(:standard -debug);
use strict;

my @counters=(0,0,0,0,0);
my (@records,$name,$event);

open(IN,'c05ex5.txt')
	or die "Error opening c05ex5.txt. $!, stopped";
@records=<IN>;
close(IN);
foreach my $rec(@records){
	chomp($rec);
	($name,$event)=split(/,/,$rec);
	$counters[0]+=1;
	$counters[$event]+=1;
}
#generate HTML
print "<HTML>\n";
print "<HEAD><TITLE>Event Information</TITLE></HEAD>\n";
print "<BODY>\n";
print "<TABLE><TR><TD><B>Seminar</B></TD><TD><B>Registered</B></TD></TR>\n";
print "<TR><TD>Computer Maintenance</TD><TD>$counters[1]</TD></TR>\n";
print "<TR><TD>Microsoft Office</TD><TD>$counters[2]</TD></TR>\n";
print "<TR><TD>Unix Essentials</TD><TD>$counters[3]</TD></TR>\n";
print "<TR><TD>CGI/Perl</TD><TD>$counters[4]</TD></TR></TABLE>\n";
print "<BR><BR>Total Registered: $counters[0]\n";
print "</BODY>\n";
print "</HTML>\n";
