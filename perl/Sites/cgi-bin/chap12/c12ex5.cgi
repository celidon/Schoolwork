#!/usr/bin/perl
#c12ex5.cgi - creates a dynamic Web page that acknowledges
#the receipt of a registration form
use CGI qw(:standard -debug);
use strict;

#declare variables
my ($name, $serial, $modnum, $sysletter);
my @models=("Laser JX","Laser PL","ColorPrint XL");
my %systems=("W","Windows",
			"M","Macintosh",
			"U","UNIX");
#assign input items to variables
$name=param('Name');
$serial=param('Serial');
$modnum=param('Model');
$sysletter=param('System');

$name =~ tr/^ +//d;
$name =~ tr/ +$//d;

$serial =~ tr/^ +//d;
$serial =~ tr/ +$//d;

if ($name eq '' or $serial eq '') {print "Location: ../../public_html/chap12/c12ex5b.html\n\n";}
else {
print "Content-type: text/html\n\n";
#create Web page
print "<HTML><HEAD><TITLE>Juniper Printers</TITLE></HEAD>\n";
print "<BODY><H2>\n";
print "Thank you, $name, for completing the registration form.<BR><BR>\n";
print "We have registered your Juniper $models[$modnum] printer, serial number $serial.<BR>\n";
print "You indicated that the printer will be used on a $systems{$sysletter} system.<BR>\n";
print "</H2></BODY></HTML>\n";
}


