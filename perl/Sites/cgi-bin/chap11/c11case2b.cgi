#!/usr/bin/perl
#c11case2b.cgi
use CGI qw(:standard -debug);

use strict;

my ($item, @items, @accessories, $name, $street, $city, $state, $zip);

$item = cookie('Item');
@items = split/ /,$item;
@accessories = ("Gold Bracelet", "Silver Bracelet", "Diamond Necklace", "Ruby Earrings", "Pearl Ring");
$name = param('Name');
$street = param('Street');
$city = param('City');
$state = param('State');
$zip = param('ZIP');

if ($name eq '' or $street eq '' or $city eq '' or $state eq '' or $zip eq '') {print "Location: ../../public_html/chap11/error.html\n\n";}
else {
print "Content-type: text/html\n\n";

print <<endHTML;
<HTML>
<HEAD><TITLE>Jarrod Accessories Online</TITLE></HEAD>
<BODY>
You have entered the following information:<BR><BR>
$name<BR>
$street<BR>
$city, $state $zip<BR><BR>
and have requested the following accessories:<BR><BR>
endHTML
foreach (@items) {print "$accessories[$_]<BR>\n";}
print "</BODY>\n</HTML>";
}
