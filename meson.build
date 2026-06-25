project(
  'mate-themes',
  meson_version: '>= 0.61.2',
  version: '3.22.26',
)

themesdir = join_paths(get_option('datadir'), 'themes')
iconsdir = join_paths(get_option('datadir'), 'icons')
excluded_files = [
  'Makefile',
  'Makefile.am',
  'Makefile.in',
]

desktop_theme_dirs = [
  'BlackMATE',
  'BlackMATE-border',
  'Blue-Submarine',
  'Blue-Submarine-border',
  'BlueMenta',
  'BlueMenta-border',
  'BlueMenta-dark',
  'ContrastHigh',
  'Green-Submarine',
  'Green-Submarine-border',
  'GreenLaguna',
  'GreenLaguna-border',
  'HighContrastInverse',
  'MateYaru',
  'MateYaru-dark',
  'Menta',
  'Menta-border',
  'TraditionalGreen',
  'TraditionalOk',
  'YaruGreen',
  'YaruOk',
]

icon_theme_dirs = [
  'ContrastHigh',
  'Fog',
  'MateYaru',
  'MateYaru-dark',
  'Quid',
]

cursor_theme_dirs = [
  'mate-black',
  'mate-white',
]

marco_theme_dirs = [
  'Aldabra',
  'Fog',
  'Glider',
  'HighContrast',
  'Quid',
  'Shiny',
]

foreach theme_dir : desktop_theme_dirs
  install_subdir(
    join_paths('desktop-themes', theme_dir),
    install_dir: themesdir,
    exclude_files: excluded_files,
  )
endforeach

foreach theme_dir : icon_theme_dirs
  install_subdir(
    join_paths('icon-themes', theme_dir),
    install_dir: iconsdir,
    exclude_files: excluded_files,
  )
endforeach

foreach theme_dir : cursor_theme_dirs
  install_subdir(
    join_paths('cursor-themes', theme_dir),
    install_dir: iconsdir,
    exclude_files: excluded_files,
  )
endforeach

foreach theme_dir : marco_theme_dirs
  install_subdir(
    join_paths('marco-themes', theme_dir),
    install_dir: themesdir,
    exclude_files: excluded_files,
  )
endforeach
