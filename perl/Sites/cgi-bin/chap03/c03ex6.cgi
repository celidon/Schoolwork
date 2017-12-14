#!/usr/bin/perl
#c03ex6.cgi - inventory calculator
print "Content-type: text/html\n\n";
use CGI qw(:standard -debug);

use strict;

my ($item, $quantity, $units, $boxes, $remains);

$item=param('Item');
$quantity=param('Quantity');
$units=param('Units');

$boxes=$quantity/$units;

$remains=$quantity%$units;

#generate HTML
print "<HTML>\n";
print "<HEAD><TITLE>Colfax Industries</TITLE></HEAD>\n";
print "<BODY>\n";
print "Item: $item<BR>\n";
printf "Quantity: %d<BR>\n", $quantity;
printf "Units per box: %d<BR>\n", $units;
printf "Full boxes: %d<BR>\n", $boxes;
printf "Remaining units: %d<BR>\n", $remains;
print "</BODY>\n";
print "</HTML>\n";
