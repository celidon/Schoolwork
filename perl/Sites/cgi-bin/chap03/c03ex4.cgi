#!/usr/bin/perl
#c03ex4.cgi - Sale calculator
print "Content-type: text/html\n\n";
use CGI qw(:standard -debug);

use strict;

my ($price, $discount, $rate, $newprice);

$price=param('Price');
$rate=param('Rate');

$discount=$price*$rate;
$newprice=$price-$discount;

#generate HTML
print "<HTML>\n";
print "<HEAD><TITLE>The Paper Tree</TITLE></HEAD>\n";
print "<BODY>\n";
print "<TABLE>\n";
print "<TR><TD>Original price: </TD><TD>"; 
printf "\$%.2f", $price;
print "</TD></TR>\n<TR><TD>Discount rate: </TD><TD>";
printf "%.1f%%", $rate*100;
print "</TD></TR>\n<TR><TD>Discount: </TD><TD>";
printf "\$%.2f", $discount;
print "</TD></TR>\n<TR><TD>Sale Price: </TD><TD>";
printf "\$%.2f", $newprice;
print "</TD></TR>\n</TABLE>";
print "</BODY>\n";
print "</HTML>\n";
