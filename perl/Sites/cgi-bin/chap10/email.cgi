#!/usr/bin/perl
#email.cgi - displays a dynamic Web page and sends an e-mail message

print "Content-type: text/html\n\n";
use CGI qw(:standard -debug);
use Mail::Sendmail;

#prevent Perl from creating undeclared variables
use strict;

#declare variables
my ($name, $email, %mail);

#assign input items to variables
$name = param('Name');
$email = param('Email');

#send e-mail message
$mail{To} = $email;
$mail{From} = 'your e-mail address';
$mail{Subject} = 'Hello Message';
$mail{Smtp} = 'your SMTP server';
$mail{Message} = "Hello, $name!";
sendmail(%mail);

#display Web page
print "<HTML>\n";
print "<HEAD><TITLE>Candles Inc.</TITLE></HEAD>\n";
print "<BODY>\n";
print "<H2>You will hear from us shortly. \n";
print "</H2></BODY></HTML>\n";
