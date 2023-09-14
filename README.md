```shell
lget add [--query] <string[]> [[--name] <string[]>] [[--list] <string[]>]
lget remove [--name] <string[]> || [--query] <string[]> [[--list] <string[]>]
```

```json
[
  listname : {
    "path": "InstallPath",
    "arr": [
      {
        "name": "nickname",
        "id": "id",
        "installed": false
      }
    ]
  },
  listname : {
    "path": "InstallPath",
    "arr": [
      {
        "name": "nickname",
        "id": "id",
        "installed": false
      }
    ]
  }
]
```

```
entry point
     ║
     ╟─>> argc, argv
     ║                  :Pars args
     ╟─<< struct args
     ║
     ║
     ║
     ╟─>> path
     ║                  :Load file
     ╟─<< file
     ║
     ║
     ║
     ╟─>> cmd, file, args, options
     ║                  :Exec
     ╟─<< ?file
     ║
     ║
     ║
     ╟─>> path, file
     ║                  :Save file
     ╟─<< void
     ║
  end point
```
