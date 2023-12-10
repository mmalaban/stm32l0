#!usr/bin/python3
"""This module generates the template, has a dependency on the template module
"""
from pathlib import Path
from dataclasses import dataclass
from datetime import date
from mako.template import Template
from .template import HEADER, SOURCE


@dataclass
class Generate:
    """Class that contains the content of what will be generated
    """
    name: str
    output: Path
    with_config: bool = False

    def __post_init__(self) -> None:
        self.__generate_h()
        self.__generate_c()

        if self.with_config:
            self.__generate_cfg()


    def __generate_h(self) -> None:
        tmplt = Template(HEADER)
        self.__generate(tmplt=tmplt, name=self.name, file_type='.h')


    def __generate_c(self) -> None:
        tmplt = Template(SOURCE)
        self.__generate(tmplt=tmplt, name=self.name, file_type='.c')


    def __generate_cfg(self) -> None:
        tmplt = Template(HEADER)
        tempname = self.name + '_Cfg'
        self.__generate(tmplt=tmplt, name=tempname, file_type='.h')


    def __generate(self, tmplt: Template, name: str, file_type: str) -> None:
        with open(f'{self.output}/{name}{file_type}', 'w', encoding='utf-8') as file:
            file.write(tmplt.render(module=name, year=date.today().year))
