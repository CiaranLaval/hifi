# add the tool directories
add_subdirectory(mtc)
set_target_properties(mtc PROPERTIES FOLDER "Tools")

add_subdirectory(scribe)
set_target_properties(scribe PROPERTIES FOLDER "Tools")

add_subdirectory(vhacd-util)
set_target_properties(vhacd-util PROPERTIES FOLDER "Tools")

