#!/usr/bin/perl
#inter.cgi - saves form data to a file, and creates
#three different dynamic Web pages
print "Content-type: text/html\n\n";
use CGI qw(:standard -debug);

#prevent Perl from creating undeclared variables
use strict;

#declare variables
my ($name, $email, $comments, $data_ok, $msg);

if ($ENV{'REQUEST_METHOD'} eq "POST") {
	($name, $email, $comments) = get_input();
	($name, $email, $comments) = format_input();
	($data_ok,$msg) = validate_input();
	if ($data_ok eq "Y") {
		save_to_file();
		create_acknowledgment_page();
	}
	else {
		create_error_page();
	}
}
else {
	create_comments_page();
}
exit;

#*****user-defined functions*****
sub get_input {
	return param('Name'), param('Email'), param('Comments');
} #end get_input

sub validate_input {
	my $valid = "Y";
	my $errormsg;
	if ($name eq "" or $email eq "" or $comments eq "") {
		$valid = "N";
		$errormsg = "complete all items";
	}
	elsif ($email !~ m/[\w\-]+\@[\w\-]+\.[\w\~]+/) {
		$valid = "N";
		$errormsg = "enter a valid e-mail address";
	}
	return $valid,$errormsg;
} #end validate_input

sub format_input {
	my ($n,$e,$c) = ($name,$email,$comments);
	$n =~ s/^ +//;
	$n =~ s/ +$//;
	$e =~ s/^ +//;
	$e =~ s/ +$//;
	$c =~ s/^\s+//;
	$c =~ s/\s+$//;
	$c =~ tr/\r\n/ /;
	$c =~ tr/ //s;
	return $n,$e,$c;
} #end format_input

sub save_to_file {
	open(OUTFILE, ">>", "comments.txt")
		or die "Error opening comments.txt for save. $!, stopped";
	print OUTFILE "$name|$email|$comments\n";
	close(OUTFILE);
} #end save_to_file

sub create_acknowledgment_page {
	print "<HTML>\n";
	print "<HEAD><TITLE>International Coffees</TITLE></HEAD>\n";
	print "<BODY>\n";
	print "<H2>$name, thank you for the following \n";
	print "comments:<BR><BR>$comments\n";
	print "</H2></BODY></HTML>\n";
} #end create_acknowledgment_page

sub create_error_page {
	print "<HTML>\n";
	print "<HEAD><TITLE>International Coffees</TITLE></HEAD>\n";
	print "<BODY>\n";
	print "<H2>Please return to the form and \n";
	print "$msg.</H2>\n";
	print "</BODY></HTML>\n";
} #end create_error_page

sub create_comments_page {
	my (@records, $name_field, $email_field, $com_field);

	open(INFILE, "<", "comments.txt")
		or die "Error opening comments.txt. $!, stopped";

	print "<HTML>\n";
	print "<HEAD><TITLE>International Coffees</TITLE></HEAD>\n";
	print "<BODY>\n";
	print "<H2>What other coffee lovers say \n";
	print "about our coffees:</H2>\n";
	@records = <INFILE>;
	close(INFILE);
	foreach my $rec (@records) {
		chomp($rec);
		($name_field, $email_field, $com_field) = split(/\|/, $rec);
		print "<B>Name:</B> $name_field<BR>\n";
		print "<B>Comments:</B> $com_field<BR>\n";
		print "<HR>";
	}
	print "</BODY></HTML>\n";
} #end create_comments_page
