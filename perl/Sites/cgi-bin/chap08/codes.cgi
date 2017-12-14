#!/usr/bin/perl
#codes.cgi - changes an area code stored in a file
use CGI qw(:standard -debug);
use strict;

#declare variables
my ($oldcode, $newcode, $name, $phone, @records);

#assign input items to variables
$oldcode = param('Old');
$newcode = param('New');

#remove leading and trailing spaces from old and new area codes

#read records from c08ex4a.txt file
#change area code and save data to the c08ex4b.txt file

