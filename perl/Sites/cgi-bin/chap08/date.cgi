#!/usr/bin/perl
#date.cgi - converts a numeric date to a string
use CGI qw(:standard -debug);
use strict;

#declare variables
my ($date);

#assign input item to variable
$date = param('Date');

#break date apart

#display date
print "Date: ";
