#!/usr/bin/perl
#c11case2a.cgi
use CGI qw(:standard -debug);

use strict;

my (@items,$C_items);

@items = param('Item');

if ($items[0] ne '')
{

$C_items = cookie(-name,'Item',-value,"@items");
print header(-cookie => $C_items);

print <<endHTML;
<HTML>
<HEAD><TITLE>Jarrod Accessories Online</TITLE></HEAD>
<BODY>
<H3><FORM ACTION="./c11case2b.cgi" METHOD=POST>
NAME: <INPUT TYPE=text NAME=Name SIZE=30><BR>
ADDRESS: <INPUT TYPE=text NAME=Street SIZE=30><BR>
CITY: <INPUT TYPE=text NAME=City SIZE=30> 
STATE: <INPUT TYPE=text NAME=State SIZE=2>
ZIP: <INPUT TYPE=text NAME=ZIP SIZE=5>
<P><INPUT TYPE=submit VALUE="SUBMIT">\t<INPUT TYPE=reset VALUE="RESET"></P>
</FORM>
</BODY>
</HTML>
endHTML
}
else {print "Location: ../../public_html/chap11/error.html\n\n";}
