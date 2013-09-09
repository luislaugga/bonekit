# Loads mkmf which is used to make makefiles for Ruby extensions
require 'mkmf'

$CFLAGS << %[ -I.. -Wall -O3 -g -std=c99]

# Give it a name
extension_name = 'bonekit'

# The destination
dir_config(extension_name)

# Do the work
create_makefile(extension_name/extension_name)