from c_code_template import Generate
from pathlib import Path

def main() -> None:
    module_name = input("Module name: ")
    directory = input("Output folder: ")
    configuration = input("Configuration (y/n)? ")

    if not Path(directory).exists():
        Path(directory).mkdir()

    if configuration.lower()[0] == 'y':
        Generate(name=module_name, output=directory, with_config=True)
    else:
        Generate(name=module_name, output=directory)

if __name__ == '__main__':
    main()
