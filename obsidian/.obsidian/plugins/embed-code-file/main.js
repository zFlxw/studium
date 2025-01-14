/*
THIS IS A GENERATED/BUNDLED FILE BY ESBUILD
if you want to view the source, please visit the github repository of this plugin
*/

var __create = Object.create;
var __defProp = Object.defineProperty;
var __getOwnPropDesc = Object.getOwnPropertyDescriptor;
var __getOwnPropNames = Object.getOwnPropertyNames;
var __getProtoOf = Object.getPrototypeOf;
var __hasOwnProp = Object.prototype.hasOwnProperty;
var __export = (target, all) => {
  for (var name in all)
    __defProp(target, name, { get: all[name], enumerable: true });
};
var __copyProps = (to, from, except, desc) => {
  if (from && typeof from === "object" || typeof from === "function") {
    for (let key of __getOwnPropNames(from))
      if (!__hasOwnProp.call(to, key) && key !== except)
        __defProp(to, key, { get: () => from[key], enumerable: !(desc = __getOwnPropDesc(from, key)) || desc.enumerable });
  }
  return to;
};
var __toESM = (mod, isNodeMode, target) => (target = mod != null ? __create(__getProtoOf(mod)) : {}, __copyProps(isNodeMode || !mod || !mod.__esModule ? __defProp(target, "default", { value: mod, enumerable: true }) : target, mod));
var __toCommonJS = (mod) => __copyProps(__defProp({}, "__esModule", { value: true }), mod);

// main.ts
var main_exports = {};
__export(main_exports, {
  default: () => EmbedCodeFile
});
module.exports = __toCommonJS(main_exports);
var import_obsidian2 = require("obsidian");

// settings.ts
var import_obsidian = require("obsidian");
var DEFAULT_SETTINGS = {
  includedLanguages: "c,cpp,java,python,go,ruby,javascript,js,typescript,ts,shell,sh,bash",
  titleBackgroundColor: "#00000020",
  titleFontColor: ""
};
var EmbedCodeFileSettingTab = class extends import_obsidian.PluginSettingTab {
  constructor(app2, plugin) {
    super(app2, plugin);
    this.plugin = plugin;
  }
  display() {
    const { containerEl } = this;
    containerEl.empty();
    containerEl.createEl("h2", { text: "Embed Code File Settings" });
    new import_obsidian.Setting(containerEl).setName("Included Languages").setDesc("Comma separated list of included languages.").addText((text) => text.setPlaceholder("Comma separated list").setValue(this.plugin.settings.includedLanguages).onChange(async (value) => {
      this.plugin.settings.includedLanguages = value;
      await this.plugin.saveSettings();
    }));
    new import_obsidian.Setting(containerEl).setName("Font color of title").addText((text) => text.setPlaceholder("Enter a color").setValue(this.plugin.settings.titleFontColor).onChange(async (value) => {
      this.plugin.settings.titleFontColor = value;
      await this.plugin.saveSettings();
    }));
    new import_obsidian.Setting(containerEl).setName("Background color of title").addText((text) => text.setPlaceholder("#00000020").setValue(this.plugin.settings.titleBackgroundColor).onChange(async (value) => {
      this.plugin.settings.titleBackgroundColor = value;
      await this.plugin.saveSettings();
    }));
  }
};

// utils.ts
var import_path = __toESM(require("path"));
function analyseSrcLines(str) {
  str = str.replace(/\s*/g, "");
  const result = [];
  let strs = str.split(",");
  strs.forEach((it) => {
    if (/\w+-\w+/.test(it)) {
      let left = Number(it.split("-")[0]);
      let right = Number(it.split("-")[1]);
      for (let i = left; i <= right; i++) {
        result.push(i);
      }
      result.push(0);
    } else {
      result.push(Number(it));
      result.push(0);
    }
  });
  return result;
}
function extractSrcLines(fullSrc, srcLinesNum) {
  let src = "";
  const fullSrcLines = fullSrc.split("\n");
  const fullSrcLinesLen = fullSrcLines.length;
  srcLinesNum.forEach((lineNum, index, arr) => {
    if (lineNum > fullSrcLinesLen) {
      arr.splice(index, 1);
    }
  });
  srcLinesNum.forEach((lineNum, index, arr) => {
    if (lineNum == 0 && arr[index - 1] == 0) {
      arr.splice(index, 1);
    }
  });
  srcLinesNum.forEach((lineNum, index) => {
    if (lineNum > fullSrcLinesLen) {
      return;
    }
    if (index == srcLinesNum.length - 1 && lineNum == 0 && srcLinesNum[index - 1] == fullSrcLinesLen) {
      return;
    }
    if (index == 0 && lineNum != 1) {
      src = "...\n" + fullSrcLines[lineNum - 1];
      return;
    }
    if (lineNum == 0) {
      src = src + "\n...";
      return;
    }
    if (index == 0) {
      src = fullSrcLines[lineNum - 1];
    } else {
      src = src + "\n" + fullSrcLines[lineNum - 1];
    }
  });
  return src;
}

// main.ts
var EmbedCodeFile = class extends import_obsidian2.Plugin {
  async onload() {
    await this.loadSettings();
    this.addSettingTab(new EmbedCodeFileSettingTab(this.app, this));
    this.registerMarkdownPostProcessor((element, context) => {
      this.addTitle(element, context);
    });
    const supportedLanguages = this.settings.includedLanguages.split(",");
    supportedLanguages.forEach((l) => {
      console.log(`registering renderer for ${l}`);
      this.registerRenderer(l);
    });
  }
  async loadSettings() {
    this.settings = Object.assign({}, DEFAULT_SETTINGS, await this.loadData());
  }
  async saveSettings() {
    await this.saveData(this.settings);
  }
  async registerRenderer(lang) {
    this.registerMarkdownCodeBlockProcessor(`embed-${lang}`, async (meta, el, ctx) => {
      let fullSrc = "";
      let src = "";
      let metaYaml;
      try {
        metaYaml = (0, import_obsidian2.parseYaml)(meta);
      } catch (e) {
        await import_obsidian2.MarkdownRenderer.renderMarkdown("`ERROR: invalid embedding (invalid YAML)`", el, "", this);
        return;
      }
      let srcPath = metaYaml.PATH;
      if (!srcPath) {
        await import_obsidian2.MarkdownRenderer.renderMarkdown("`ERROR: invalid source path`", el, "", this);
        return;
      }
      if (srcPath.startsWith("https://") || srcPath.startsWith("http://")) {
        try {
          let httpResp = await (0, import_obsidian2.requestUrl)({ url: srcPath, method: "GET" });
          fullSrc = httpResp.text;
        } catch (e) {
          const errMsg = `\`ERROR: could't fetch '${srcPath}'\``;
          await import_obsidian2.MarkdownRenderer.renderMarkdown(errMsg, el, "", this);
          return;
        }
      } else if (srcPath.startsWith("vault://")) {
        srcPath = srcPath.replace(/^(vault:\/\/)/, "");
        const tFile = app.vault.getAbstractFileByPath(srcPath);
        if (tFile instanceof import_obsidian2.TFile) {
          fullSrc = await app.vault.read(tFile);
        } else {
          const errMsg = `\`ERROR: could't read file '${srcPath}'\``;
          await import_obsidian2.MarkdownRenderer.renderMarkdown(errMsg, el, "", this);
          return;
        }
      } else {
        const errMsg = "`ERROR: invalid source path, use 'vault://...' or 'http[s]://...'`";
        await import_obsidian2.MarkdownRenderer.renderMarkdown(errMsg, el, "", this);
        return;
      }
      let srcLinesNum = [];
      const srcLinesNumString = metaYaml.LINES;
      if (srcLinesNumString) {
        srcLinesNum = analyseSrcLines(srcLinesNumString);
      }
      if (srcLinesNum.length == 0) {
        src = fullSrc;
      } else {
        src = extractSrcLines(fullSrc, srcLinesNum);
      }
      let title = metaYaml.TITLE;
      if (!title) {
        title = srcPath;
      }
      await import_obsidian2.MarkdownRenderer.renderMarkdown("```" + lang + "\n" + src + "\n```", el, "", this);
      this.addTitleLivePreview(el, title);
    });
  }
  addTitleLivePreview(el, title) {
    const codeElm = el.querySelector("pre > code");
    if (!codeElm) {
      return;
    }
    const pre = codeElm.parentElement;
    this.insertTitlePreElement(pre, title);
  }
  addTitle(el, context) {
    let codeElm = el.querySelector("pre > code");
    if (!codeElm) {
      return;
    }
    const pre = codeElm.parentElement;
    const codeSection = context.getSectionInfo(pre);
    if (!codeSection) {
      return;
    }
    const view = app.workspace.getActiveViewOfType(import_obsidian2.MarkdownView);
    if (!view) {
      return;
    }
    const num = codeSection.lineStart;
    const codeBlockFirstLine = view.editor.getLine(num);
    let matchTitle = codeBlockFirstLine.match(/TITLE:\s*"([^"]*)"/i);
    if (matchTitle == null) {
      return;
    }
    const title = matchTitle[1];
    if (title == "") {
      return;
    }
    this.insertTitlePreElement(pre, title);
  }
  insertTitlePreElement(pre, title) {
    pre.querySelectorAll(".obsidian-embed-code-file").forEach((x) => x.remove());
    let titleElement = document.createElement("pre");
    titleElement.appendText(title);
    titleElement.className = "obsidian-embed-code-file";
    titleElement.style.color = this.settings.titleFontColor;
    titleElement.style.backgroundColor = this.settings.titleBackgroundColor;
    pre.prepend(titleElement);
  }
};

/* nosourcemap */