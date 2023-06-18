from setuptools import setup

package_name = 'jaybot'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
             ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Nick',
    maintainer_email='ncr5012@gmail.com',
    description='Package to allow a robot to learn on its own',
    license='No license authorized to anybody at any time',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'rl_mind = jaybot.scripts.rl_mind:main',
        ],
    },
)
