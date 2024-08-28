
# CLI Spellchecker

A simple command-line tool to check spelling in a text file against a list of English words. It downloads a word list from a GitHub repository and identifies potential typos in the provided file.

### Requirements

- Rust *(if not installed, click [here](https://www.rust-lang.org/learn/get-started))*

### Dependencies

- `reqwest` for HTTP requests
- `tokio` for asynchronous runtime

### Installation

1. install the dependencies and build the project:
    ```sh
    cargo build
	```

### Usage

run the spellchecker from the command line with:
```sh
cli-spellchecker.exe <file>
```