#!/usr/bin/perl
#c05ex2.cgi - saves form data to a file, and creates a dynamic
#Web page that displays a message and survey statistics
print "Content-type: text/html\n\n";
use CGI qw(:standard -debug);
use strict;

#declare variables
my ($game, $commercial, @records);
my @game_count=(0,0,0);
my %comm_count=("Budweiser", 0,
				"FedEx", 0,
				"MasterCard", 0,
				"Pepsi", 0);
#assign input items to variables
$game=param('Game');
$commercial=param('Commercial');
#save form data to a file
open(OUTFILE, ">>", "c05ex2.txt")
	or die "Error opening c05ex2.txt. $!, stopped";
print OUTFILE "$game,$commercial\n";
close(OUTFILE);
#calculate survey statistics
open(INFILE,"<","c05ex2.txt")
	or die "Error opening c05ex2.txt. $!, stopped";
@records=<INFILE>;
close(INFILE);
foreach my $rec(@records){
	chomp($rec);
	($game,$commercial)=split(/,/,$rec);
	$game_count[$game]+=1;
	$comm_count{$commercial}+=1;
}
#generate HTML acknowledgment
print "<HTML><HEAD><TITLE>WKRK-TV</TITLE></HEAD>\n";
print "<BODY>\n";
print "<H2>Thank you for participating in our survey.</H2>\n";

print "<EM><B>What did you think of the Super Bowl game?</EM></B>\n";
print "<TABLE>\n";
print "<TR><TD>It was a great game.</TD>    <TD>$game_count[0]</TD></TR>\n";
print "<TR><TD>It was a boring game.</TD>   <TD>$game_count[1]</TD></TR>\n";
print "<TR><TD>I didn't watch the game.</TD><TD>$game_count[2]</TD></TR>\n";
print "</TABLE><BR>\n";

print "<EM><B>Vote for your favorite Super Bowl commercial:</EM></B>\n";
print "<TABLE>\n";
foreach my $key (sort(keys(%comm_count))){
	print "<TR><TD>$key</TD><TD>$comm_count{$key}</TD></TR>\n";
}
print "</TABLE>\n";
print "</BODY></HTML>\n";
