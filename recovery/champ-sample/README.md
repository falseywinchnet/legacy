# Original CHAMP sample database reference

`tables.json` contains all 19 user tables and 670 rows from the preserved
`originals/champ2/sample.mdb`. It was read independently with MDB Tools 1.0.1
through `tools/capture_access_reference.cpp`, retaining every stored float value,
empty string, null, and Boolean. Row order is not a property of an Access table;
comparisons use a multiset of complete rows.

The native C++ Jet reader in `src/champ/access.cpp` matches every cell. The product
has no MDB Tools, Access, ODBC, Java, or external conversion dependency.

Reproduce the independent extraction with MDB Tools development headers installed:

```sh
c++ -std=c++20 -Ithird_party tools/capture_access_reference.cpp \
  -o build/capture-access $(pkg-config --cflags --libs libmdb)
build/capture-access originals/champ2/sample.mdb recovery/champ-sample/tables.json
```

MDB Tools is LGPL licensed and used only as an independent research reference.
Its [file-format documentation](https://github.com/mdbtools/mdbtools/blob/dev/HACKING.md)
was used to implement the independent native reader.
