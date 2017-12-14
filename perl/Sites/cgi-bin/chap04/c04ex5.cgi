#!/usr/bin/perl
#c04ex5.cgi - creates a dynamic Web page that acknowledges
#the receipt of a registration form
print "Content-type: text/html\n\n";
use CGI qw(:standard -debug);
use strict;

#declare variables
my ($name, $serial, $modnum, $sysletter,$use);
my @models=("Laser JX","Laser PL","ColorPrint XL");
my @uses=("Home","Business","Educational","Other");
my %systems=("W","Windows",
			"M","Macintosh",
			"U","UNIX");
#assign input items to variables
$name=param('Name');
$serial=param('Serial');
$modnum=param('Model');
$sysletter=param('System');
my @primary_uses=param("Use");
#create Web page
print "<HTML><HEAD><TITLE>Juniper Printers</TITLE></HEAD>\n";
print "<BODY><H2>\n";
print "Thank you, $name, for completing the registration form.<BR><BR>\n";
print "We have registered your Juniper $models[$modnum] printer, serial number $serial.<BR>\n";
print "You indicated that the printer will be used on a $systems{$sysletter} system.<BR><BR>\n";
print "The primary use(s) for this printer is(are):<BR><BR>\n";
foreach $use (@primary_uses) { print "$uses[$use]<BR>\n";}
print "</H2></BODY></HTML>\n";



