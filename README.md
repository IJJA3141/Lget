```shell
lget add -l listname -q exemple.id -n nick name of package  # need list and id -n name will be used for the path
lget remove -l listname or -q exemple.id                    # could pass a list or an id
lget remove -l listname -q exemple.id                       # if list and id are passed
                                                            # will only remove in specified list
lget make newlistname -p pathtoinstalldir -l listname       # create new list -p for path -l for template list

lget install -l                                             # install if no list specified, install all ids else only in specified list
lget uninstall -l                                           # uninstall if no list specified, uninstall all ids else only in specified list

lget path -l or -q                                          # if no list specified add the package root folder to path if it is add all package of list
```
