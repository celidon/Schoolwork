#!/usr/bin/perl
#c07ex1.cgi - saves form data to a file, and creates
#three different dynamic Web pages
print "Content-type: text/html\n\n";
use CGI qw(:standard -debug);

#prevent Perl from creating undeclared variables
use strict;

#declare variables
my ($name, $email, $comments, $data_ok, @err);

if ($ENV{'REQUEST_METHOD'} eq "POST") {
	($name, $email, $comments) = get_input();
	$data_ok = validate_input();
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
	return param('Name'),param('Email'),param('Comments');
} #end get_input

sub validate_input {
	my $valid = 'Y';
	if ($name eq '' or $email eq '' or $comments eq '') {
		$valid = 'N';
		if ($name eq '') { push(@err, "Please input a name"); }
		if ($email eq '') { push(@err, "Please input an email"); }
		if ($comments eq '') { push(@err, "Please input a comment"); }
	}
	return $valid;
} #end validate_input

sub save_to_file {
	open(OUTFILE, ">>", "c07ex1.txt")
		or die "Error opening c07ex1.txt for save. $!, stopped";
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
	my $size=@err;
	print "<HTML>\n";
	print "<HEAD><TITLE>International Coffees</TITLE></HEAD>\n";
	print "<BODY>\n";
	print "<H2>Please return to the form and \n";
	print "complete the following items:</H2><BR><BR>\n";
	for (my $i=0; $i<$size; $i+=1) { print "$err[$i]<BR>\n";}
	print "</BODY></HTML>\n";
} #end create_error_page

sub create_comments_page {
	my (@records, $name_field, $email_field, $com_field);

	open(INFILE, "<", "c07ex1.txt")
		or die "Error opening c07ex1.txt. $!, stopped";

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
