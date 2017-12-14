#!/usr/bin/perl
#name.cgi - changes last name and first name to first name and last name
use CGI qw(:standard -debug);
use strict;

#declare variables
my ($name);

#assign input item to variable
$name = param('Name');

#remove leading and trailing spaces from name

#remove spaces from within name

#locate comma

#assign last name and first name to variables

#print first name and last name separated by a space
