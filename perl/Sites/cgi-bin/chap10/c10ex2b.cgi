#!/usr/bin/perl
#c10ex2b.cgi - displays a dynamic Web page and sends e-mail that 
#acknowledges the request for information

print "Content-type: text/html\n\n";
use CGI qw(:standard -debug);

#prevent Perl from creating undeclared variables
use strict;

#declare variables
my (@brochure, $name, $email, $msg,%mail,$size);

#assign input items to variables
@brochure = param('Brochure');
$name = param('H_name');
$email = param('H_email');
#create message
$msg = "Thank you, $name. We have received your request for a \n";
$msg = $msg . "brochure on"; 
$size = @brochure;
for(my $i = 0;$i < $size;$i+=1) {
	if ($i > 0) {
		if ($i==$size-1) {$msg = $msg . " and $brochure[$i]";}
		else {$msg = $msg . ", $brochure[$i]";}
	}
	else {$msg = $msg . " $brochure[$i]";}
}
$msg = $msg . ".\n We will mail the brochure \n";
$msg = $msg . "to you as soon as possible.";

#create Web page acknowledgment
print "<HTML>\n";
print "<HEAD><TITLE>Sun Travel</TITLE></HEAD>\n";
print "<BODY>\n";
print "<H1>Sun Travel</H1><HR>\n";
print "<H2>$msg</H2>\n";
print "</BODY></HTML>\n";

#send e-mail acknowledgment
$mail{To} = $email;
$mail{From} = 'email@email.email';
$mail{Subject} = 'Travel Information';
$mail{Smtp} = 'email.email';
$mail{Message} = $msg;
