# Ninja with compilation DB extension for Android development in C/C++

```bash
usage: ninja -t compdb [options] [rules]

options:
  -x     expand @rspfile style response file invocations
  -w     workspace root path
  -c     pattern to identify the compiler path.
           (default: prebuilts/)
           : prefix string before the pattern will be replaced
             with the workspace root path
  -r     paths to be removed in command. concatenated with ','
  -p     list of prefix paths. concatenated with ','
  -i     list of input extensions. concatenated with ','
           (default: .c,.cc,.cpp)
  -o     list of output extensions. concatenated with ','
           (default: .o)
```

When one of above options is used (except '-x' which is existing option), output is customized for AOSP.
`compile_commands.json` from this command can be used for [Clion](https://www.jetbrains.com/clion/) or [cquery](https://github.com/cquery-project/cquery) for Android development in C/C++.

## example

```bash
./ninja -f out/build-aosp.ninja compdb -w /path/to/top -p prefix/to/include1,prefix/to/include2 -r /absolute/prefix/path/string/to/remove/  2> /dev/null

./ninja -f out/build-54c6166df8be61bc4783b15563a4dfb6.ninja -t compdb -w /build/gbae/dev-camera -p vendor/nvidia/tegra/camera-partner/ -r /tegrabuild/gbae/android 2> /dev/null > compile_commands.json
```

# Original README from https://github.com/ninja-build/ninja

Ninja is a small build system with a focus on speed.
https://ninja-build.org/

See the manual -- https://ninja-build.org/manual.html or
doc/manual.asciidoc included in the distribution -- for background
and more details.

Binaries for Linux, Mac, and Windows are available at
  https://github.com/ninja-build/ninja/releases
Run './ninja -h' for Ninja help.

To build your own binary, on many platforms it should be sufficient to
just run `./configure.py --bootstrap`; for more details see HACKING.md.
(Also read that before making changes to Ninja, as it has advice.)

Installation is not necessary because the only required file is the
resulting ninja binary. However, to enable features like Bash
completion and Emacs and Vim editing modes, some files in misc/ must be
copied to appropriate locations.

If you're interested in making changes to Ninja, read HACKING.md first.
