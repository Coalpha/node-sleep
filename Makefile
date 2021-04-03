ifeq ($(OS), Windows_NT)
	gyp_cache := $(subst \,/,${HOME})/AppData/Local/node-gyp/Cache
else
	gyp_cache := ${HOME}/.cache/node-gyp
endif

node_include := $(word 1,$(wildcard $(gyp_cache)/*/))include/node

compile_flags.txt:
	$(file >$@)
	$(file >>$@,-Wall)
	$(file >>$@,-Wextra)
	$(file >>$@,-I$(node_include))
	$(file >>$@,-Inode_modules/node-addon-api)

src := sleep.cxx
bin := build/Release/sleep.node

$(bin): $(src)
	npx node-gyp rebuild

print: $(bin)
	node -e "console.log(require('.'))"

clean:
	npx node-gyp clean

.PHONY: compile_flags.txt print clean
