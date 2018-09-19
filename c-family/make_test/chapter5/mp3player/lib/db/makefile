#最后还有一个复杂的地方。如果标准的c编译模式规则无法找到匹配的
#二进制文件爱你输出路径，则lex的隐含规则以及我们的yacc莫会成规则
#也会匹配失败。我们可以手动更新这些规则，因为它们再也无法应用到其他
#的lex或yacc文件中。所以我们把它们移到lib/moudle.mk：
local_dir := $(BINARY_DIR)/$(subdirectory)
local_src := $(addprefix $(subdirectory)/,playlist.y scanner.l)

$(eval $(call make-library,$(subdirectory)/libdb.a,$(local_src)))

$(eval $(compile-rules))

.SECONDARY: $(call generated-source, $(local_src))

$(local_dir)/scanner.d: $(local_dir)/playlist.d

$(local_dir)/$.c $(local_dir)/%.h: $(subdirectory)/%.y
	$(YACC.y) --defines $<
	$(MV) y.tab.c $(dir $@)$*.c
	$(MV) y.tab.h $(dir $@)$*.h

$(local_dir)/scanner.c: $(subdirectory)/scanner.l
	@$(RM) $@
	$(LEX.l) $< > $@