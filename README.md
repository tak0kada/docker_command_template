## docker\_command\_template
* Runs executable file in a docker container as if it is a local file.
* Limitation:
  * Any directories or files should be specified with an absolute path.
  * Note that malicious program can get root access.

## Usage
If you can modify the path inside the executable like ``input_path  = "/hostroot" + input_path``:

```sh
./main --input /path/to/input --output /path/to/output --param 1
```

Or if you can not modify the executable:
```sh
./main --input /hostroot/path/to/input --output /hostroot/path/to/output --param 1
```
