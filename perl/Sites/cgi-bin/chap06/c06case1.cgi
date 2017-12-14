#!/usr/bin/perl
#c06case1.cgi
print "Content-type: text/html\n\n";
use CGI qw(:standard -debug);
use strict;

my ($name,$p1,$p2,$mid,$fin,$tot,@err,$size);

$name=param("Name");
$p1=param("P1");
$p2=param("P2");
$mid=param("Midterm");
$fin=param("Final");

if($name eq ""){push(@err,"Student Name field empty");}

if($p1 eq ""){push(@err,"Project 1 Points field empty");}
elsif($p1 < 0){push(@err,"Project 1 Points too low");}
elsif($p1 > 50){push(@err,"Project 1 Points too high");}

if($p2 eq ""){push(@err,"Project 2 Points field empty");}
elsif($p2 < 0){push(@err,"Project 2 Points too low");}
elsif($p2 > 50){push(@err,"Project 2 Points too high");}

if($mid eq ""){push(@err,"Midterm Points field empty");}
elsif($mid < 0){push(@err,"Midterm Points too low");}
elsif($mid > 100){push(@err,"Midterm Points too high");}

if($fin eq ""){push(@err,"Final Points field empty");}
elsif($fin < 0){push(@err,"Final Points too low");}
elsif($fin > 100){push(@err,"Final Points too high");}

$size=@err;
if($size>0){
#generate HTML
print "<HTML>\n";
print "<HEAD><TITLE>Mountain Community College</TITLE></HEAD>\n";
print "<BODY>\n";
print "Error with scores data.<BR>Please go back and correct the following errors:<BR><BR>\n";
for(my $i=0;$i<$size;$i+=1){print "$err[$i]<BR>\n";}
print "</BODY>\n";
print "</HTML>\n";
}
else{
$tot=$p1+$p2+$mid+$fin;
open(OUT,">>",'c06case1.txt') or die "Error opening c06case1.txt. $!, stopped";
print OUT "$name,$tot\n";
close(OUT);
print "<HTML>\n";
print "<HEAD><TITLE>Mountain Community College</TITLE></HEAD>\n";
print "<BODY>Student:$name\tPoints:$tot<BR>has been saved to c06case1.txt</BODY>\n";
print "</HTML>\n";
}
