#!/usr/bin/perl
#c11ex2b.cgi - displays a Web page containing the user's
#name and the book information
use CGI qw(:standard -debug);

#prevent Perl from creating undeclared variables
use strict;

#declare variables
my ($name, $C_name, $email, $C_email);

#assign input to variable
$name = param('Name');
$email = param('Email');
#create cookie
$C_name = cookie(-name => 'Name',
				 -value => "$name",
				 -path => "../../cgi-bin/chap11",
				 -expires => "+6M");

$C_email = cookie(-name => 'Email',
				 -value => "$email",
				 -path => "../../cgi-bin/chap11",
				 -expires => "+6M");

#send cookie to browser
print header(-cookie => [$C_name,$C_email]);

#create Web page
print "<HTML>\n";
print "<HEAD><TITLE>Jubilee Book Club</TITLE></HEAD>\n";
print "<BODY>\n";
print "<H1 ALIGN=center>Hello, $name!<BR>\n";
print "The book of the month is</H1><HR>\n";
print "<H2 ALIGN=center><FONT COLOR=red>\n";
print "<I>The Case of the Missing Dagger</I>\n";
print "<BR>by H.T. Sims\n";
print "</FONT></H2>\n";
print "</BODY></HTML>\n";

