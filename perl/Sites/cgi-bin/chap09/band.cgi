#!/usr/bin/perl
#band.cgi - saves data to and removes data from a database
#creates appropriate dynamic Web pages
print "Content-type: text/html\n\n";
use CGI qw(:standard -debug);

use SDBM_File;
use Fcntl;

#prevent Perl from creating undeclared variables
use strict;

#declare variables
my ($button, $name, $email);

#assign values to variables
$button = param('Button');
$name = param('Name');
$email = param('Email');

if ($button eq "Put Me On Your Mailing List") {add();}
elsif ($button eq "Remove Me From Your Mailing List") {remove();}
exit;

#*****user-defined functions*****
sub add {
	#declare variable
	my %mail;

	#open database, add record, close database
	tie(%mail,"SDBM_File","maillist",O_CREAT|O_RDWR,0666)
		or die "Error opening maillist. $!, stopped";
	$mail{$email} = $name;
	untie(%mail);

	#create Web page
	print "<HTML>\n";
	print "<HEAD><TITLE>The Jeffrey Sikes Band</TITLE></HEAD>\n";
	print "<BODY BGCOLOR=silver>\n";
	print "<FONT SIZE=5>\n";
	print "<H1>The Jeffrey Sikes Band</H1>\n";
	print "Thank you, $name. We will send the monthly \n";
	print "newsletter to $email.\n";
	print "</FONT></BODY></HTML>\n";
} #end add

sub remove {
	#declare variables
	my (%mail, $msg);

	#open database
	tie(%mail, "SDBM_File", "maillist", O_RDWR, 0)
		or die "Error opening maillist. $!, stopped";
	
	#determine if user's information is in the database
	if (exists($mail{$email})) {
	delete($mail{$email});
	$msg = "Thank you, $name. We have removed your ";
	$msg = $msg . "information from our mailing list.";
	}
	else {$msg = "You are not on our mailing list.";}			
	#close database
	untie(%mail);

	#create Web page
	print "<HTML>\n";
	print "<HEAD><TITLE>The Jeffrey Sikes Band</TITLE></HEAD>\n";
	print "<BODY BGCOLOR=silver>\n";
	print "<FONT SIZE=5>\n";
	print "<H1>The Jeffrey Sikes Band</H1>\n";
	print "$msg\n";
	print "</FONT></BODY></HTML>\n";
} #end remove
