from setuptools import find_packages
from setuptools import setup

setup(
    name='quadropted_msgs',
    version='0.1.0',
    packages=find_packages(
        include=('quadropted_msgs', 'quadropted_msgs.*')),
)
