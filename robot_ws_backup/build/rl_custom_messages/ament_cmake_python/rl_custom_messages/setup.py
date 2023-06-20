from setuptools import find_packages
from setuptools import setup

setup(
    name='rl_custom_messages',
    version='0.0.0',
    packages=find_packages(
        include=('rl_custom_messages', 'rl_custom_messages.*')),
)
