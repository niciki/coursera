(window.webpackJsonp=window.webpackJsonp||[]).push([[100],{"24m0":function(module,exports){exports.default={"Complete":"Пройден","Completed":"Пройденные","Go to next item":"Перейти к следующему пункту","Mark as completed":"Пометить как выполненное","Reading completed":"Чтение завершено"}},"2ReX":function(module,e,t){"use strict";var n={NAME:"NAME",USER_ID:"USER_ID",HASHED_USER_ID:"HASHED_USER_ID"};e.a=n;var r=n.NAME,a=n.USER_ID,o=n.HASHED_USER_ID},BudH:function(module,e,t){"use strict";e.a={supplementsApi:"onDemandSupplements.v1"}},GbZe:function(module,exports,e){},Hpzv:function(module,exports,e){var t=e("GbZe"),n;"string"==typeof t&&(t=[[module.i,t,""]]);var r={transform:void 0},a=e("aET+")(t,r);t.locals&&(module.exports=t.locals)},MC18:function(module,exports,e){var t=e("24m0"),n=t.default?t.default:{},r,a=(0,e("HdzH").default)(n);a.getLocale=function(){return"ru"},module.exports=a},PgCP:function(module,e,t){"use strict";var n=t("S+eF"),r=t.n(n),a=t("15pW"),o=t("TSOT"),c=Object(o.a)(a.d.supplementCompletionApi,{type:"rest"}),i=Object(o.a)(a.d.supplementStartApi,{type:"rest"});function updateSupplementProgress(e){var t=e.itemId,n=e.courseId,a=e.userId,o=e.api,c={data:{userId:a,courseId:n,itemId:t}};return r()(o.post("",c))}var s={markComplete:function markComplete(e,t,n){return updateSupplementProgress({itemId:e,courseId:t,userId:n,api:c})},markStarted:function markStarted(e,t,n){return updateSupplementProgress({itemId:e,courseId:t,userId:n,api:i})}};e.a=s;var u=s.markComplete,d=s.markStarted},"Q/rb":function(module,e,t){"use strict";var n=t("VkAN"),r=t.n(n),a=t("AeFk"),o=t("q1tI"),c=t.n(o),i=t("763+"),s=t("YmkS"),u=t("WN9/"),d=t.n(u);function _templateObject2(){var e=r()(["\n    border-top: 1px solid #ddd;\n    padding: 15px 0;\n  "]);return _templateObject2=function _templateObject2(){return e},e}function _templateObject(){var e=r()(["\n    max-width: 960px;\n    color: #1f1f1f;\n\n    margin-top: ",";\n    "," {\n      margin-top: ",";\n    }\n    "," {\n      margin-top: ",";\n    }\n  "]);return _templateObject=function _templateObject(){return e},e}var p=function ItemBox(e){var t=e.className,n=e.computedItem,r=e.feedbackType,o=e.hideFeedback,c=e.children,u=Object(i.a)(),d=Object(a.c)(_templateObject(),u.spacing(24),u.breakpoints.up("sm"),u.spacing(32),u.breakpoints.up("md"),u.spacing(48)),p=Object(a.c)(_templateObject2());return Object(a.d)("div",{className:t,css:d},c,!o&&n&&r&&Object(a.d)("div",{css:p},Object(a.d)(s.a,{computedItem:n,itemFeedbackType:r})))};e.a=p},UEkh:function(module,e,t){"use strict";var n=t("VkAN"),r=t.n(n),a=t("VbXa"),o=t.n(a),c=t("AeFk"),i=t("q1tI"),s=t.n(i),u=t("17x9"),d=t.n(u),p=t("MnCE"),l=t("+LJP"),m=t("sQ/U"),b=t("15pW"),g=t("8Hdl"),f=t("ZJgU"),O=t("oEqI"),j=t("/szJ"),I=t("PgCP"),v=t("E4RX"),h=t("MC18"),S=t.n(h);function _templateObject4(){var e=r()(["\n                  "," {\n                    margin-top: ",";\n                  }\n                "]);return _templateObject4=function _templateObject4(){return e},e}function _templateObject3(){var e=r()(["\n                  margin-right: ",";\n                "]);return _templateObject3=function _templateObject3(){return e},e}function _templateObject2(){var e=r()(["\n                display: flex;\n                flex-direction: row;\n\n                "," {\n                  margin-top: ",";\n                }\n              "]);return _templateObject2=function _templateObject2(){return e},e}function _templateObject(){var e=r()(["\n              display: flex;\n              align-items: center;\n              "," {\n                flex-direction: column;\n                align-items: flex-start;\n              }\n            "]);return _templateObject=function _templateObject(){return e},e}var C=function(e){function ReadingCompleteButton(){for(var t,n=arguments.length,r=new Array(n),a=0;a<n;a++)r[a]=arguments[a];return(t=e.call.apply(e,[this].concat(r))||this).markComplete=function(){var e=t.context.executeAction,n=t.props,r=n.itemId,a=n.courseId,o=n.courseProgress,c;o.getItemProgress(r).setState(b.e),e(v.c,{courseProgress:o}),Object(v.b)(o.get("id"),o),I.a.markComplete(r,a,m.a.get().id).done()},t.goToNextItem=function(){var e=t.props,n=e.nextItem,r=e.router;n&&r.push(n.getLink())},t}var t;return o()(ReadingCompleteButton,e),ReadingCompleteButton.prototype.render=function render(){var e=this.props,t=e.isComplete,n=e.nextItem,r=e.theme;return Object(c.d)("div",{className:"rc-ReadingCompleteButton horizontal-box"},t?Object(c.d)("div",{className:"completed",css:Object(c.c)(_templateObject(),r.breakpoints.down("xs"))},Object(c.d)("div",{css:Object(c.c)(_templateObject2(),r.breakpoints.down("xs"),r.spacing(32))},Object(c.d)(j.a,{size:"large",color:"success",title:S()("Reading completed")})," ",Object(c.d)(g.a,{variant:"h3bold",color:"success",css:Object(c.c)(_templateObject3(),r.spacing(24))},S()("Completed"))),!!n&&Object(c.d)(f.a,{css:Object(c.c)(_templateObject4(),r.breakpoints.down("xs"),r.spacing(32)),variant:"primary",type:"submit",onClick:this.goToNextItem},S()("Go to next item"))):Object(c.d)(f.a,{variant:"primary",type:"submit",onClick:this.markComplete},S()("Mark as completed")))},ReadingCompleteButton}(s.a.Component);C.contextTypes={router:d.a.object,executeAction:d.a.func.isRequired},e.a=Object(p.compose)(Object(l.a)(function(e){return{router:e}}),O.a)(C)},fZ4b:function(module,e,t){"use strict";var n=t("BudH"),r=t("K7Vu");e.a=function(e){var t=e.itemId,a=e.courseId,o=e.courseSlug,c,i={includes:["asset"],fields:["openCourseAssets.v1(typeName)","openCourseAssets.v1(definition)"]};return new r.a({itemId:t,courseId:a,courseSlug:o}).getWithCourseItemId(n.a.supplementsApi,i).then(function(e){return e.linked["openCourseAssets.v1"][0]})}},j0VE:function(module,e,t){"use strict";var n=t("VbXa"),r=t.n(n),a=t("q1tI"),o=t.n(a),c=t("MnCE"),i=t("ZJgU"),s=t("KXbA"),u=t("G2Rf"),d=t("PamN"),p=t("9A5E"),l=t("NzvK"),m=t.n(l),b=function(e){function LabSandboxLauncherButton(){for(var t,n=arguments.length,r=new Array(n),a=0;a<n;a++)r[a]=arguments[a];return(t=e.call.apply(e,[this].concat(r))||this).handleClick=function(){var e=t.props.courseSlug,n=Object(d.c)(e);window.open(n,"_blank")},t}var t;return r()(LabSandboxLauncherButton,e),LabSandboxLauncherButton.prototype.render=function render(){var e=this.props,t=e.courseId,n=e.courseBranchId,r=e.itemId,a=e.ownsCourse,c=e.isFreeTrial;if(!Object(d.b)(t,n,r,a,c))return null;return o.a.createElement("div",{className:"rc-LabSandboxLauncherButton"},o.a.createElement(i.a,{variant:"ghost",component:p.a,iconPosition:"before",trackingName:"lab_sandbox",href:"/learn/".concat(this.props.courseSlug,"/lab-sandbox"),target:"_blank",icon:o.a.createElement(s.a,{size:"small"}),"aria-label":m()("open lab sandbox")},m()("Practice with Lab Sandbox")))},LabSandboxLauncherButton}(a.Component);e.a=Object(c.compose)(u.a)(b)},kDtP:function(module,e,t){"use strict";var n=t("VbXa"),r=t.n(n),a=t("q1tI"),o=t.n(a),c=t("37kS"),i=t.n(c),s=t("Hpzv"),u=t.n(s),d=function(e){function LoadingIndicator(){return e.apply(this,arguments)||this}var t;return r()(LoadingIndicator,e),LoadingIndicator.prototype.render=function render(){return o.a.createElement("div",{className:"rc-LoadingIndicator"},i()("Loading"))},LoadingIndicator}(o.a.Component);e.a=d},wrpb:function(module,e,t){"use strict";t.r(e),t.d(e,"ReadingItem",function(){return E});var n=t("lSNA"),r=t.n(n),a=t("VbXa"),o=t.n(a),c=t("VkAN"),i=t.n(c),s=t("AeFk"),u=t("q1tI"),d=t.n(u),p=t("MnCE"),l=t("8cuT"),m=t("sQ/U"),b=t("fZ4b"),g=t("8Hdl"),f=t("oEqI"),O=t("7GkZ"),j=t("2ReX"),I=t("hUuC"),v=t("h4VP"),h=t("UEkh"),S=t("kDtP"),C=t("Q/rb"),k=t("j0VE");function _templateObject3(){var e=i()(["\n    margin-bottom: ",";\n  "]);return _templateObject3=function _templateObject3(){return e},e}function _templateObject2(){var e=i()(["\n    max-width: 790px;\n  "]);return _templateObject2=function _templateObject2(){return e},e}function _templateObject(){var e=i()(["\n    margin-bottom: ",";\n    "," {\n      margin-bottom: ",";\n    }\n  "]);return _templateObject=function _templateObject(){return e},e}var x={negativeMarginLeft:Object(s.c)({marginLeft:"-16px"}),title:function title(e){return Object(s.c)(_templateObject(),e.spacing(32),e.breakpoints.up("md"),e.spacing(48))},cmlRestyling:Object(s.c)(_templateObject2()),body:function body(e){return Object(s.c)(_templateObject3(),e.spacing(48))}},E=function(e){function ReadingItem(){for(var t,n=arguments.length,r=new Array(n),a=0;a<n;a++)r[a]=arguments[a];return(t=e.call.apply(e,[this].concat(r))||this).state={readingCml:null},t}o()(ReadingItem,e);var t=ReadingItem.prototype;return t.componentDidMount=function componentDidMount(){var e=this,t=this.props,n=t.computedItem,r=t.courseId,a=t.courseSlug,o=n.id;Object(b.a)({itemId:o,courseId:r,courseSlug:a}).then(function(t){e.setState({readingCml:t})})},t.renderExternalActions=function renderExternalActions(){var e=this.props,t=e.computedItem,n=e.courseId,r=e.courseSlug,a=e.branchId;return Object(s.d)("div",{css:x.negativeMarginLeft},Object(s.d)(k.a,{courseId:n,courseBranchId:a,itemId:t.id,courseSlug:r}))},t.renderTitle=function renderTitle(){var e=this.props,t=e.computedItem,n=e.theme,r=this.state.readingCml;if(!r)return null;var a=Object(v.d)(r);if(a&&Object(v.h)(a,"1")&&I.d.getInnerContent(a)===t.name)return null;return Object(s.d)("div",{className:"reading-title",css:x.title(n)},Object(s.d)(g.a,{variant:"d2",component:"h1"},t.name),this.renderExternalActions())},t.render=function render(){var e,t,n=this.props,a=n.computedItem,o=n.courseId,c=n.courseSlug,i=n.itemMetadata,u=n.courseMaterials,d=n.courseProgress,p=n.theme,l=this.state.readingCml,b=j.a.NAME,g=j.a.USER_ID,f=null==u?void 0:null===(e=u.getNeighbors(i))||void 0===e?void 0:e.nextItemMetadataOrItemGroup;return Object(s.d)(C.a,{className:"rc-ReadingItem",feedbackType:"reading",computedItem:a,courseId:o,css:x.cmlRestyling},Object(s.d)("div",{css:x.body(p)},l?Object(s.d)("div",null,this.renderTitle(),Object(s.d)(O.a,{cml:l,isCdsEnabled:!0,shouldApplyTracking:!0,variableData:(t={},r()(t,b,m.a.get().fullName),r()(t,g,m.a.get().id),t)}),Object(s.d)(h.a,{courseId:o,courseSlug:c,itemId:a.id,isComplete:a.isCompleted,nextItem:f,courseProgress:d})):Object(s.d)(S.a,null)))},ReadingItem}(d.a.Component);e.default=Object(p.compose)(Object(l.a)(["CourseStore","ProgressStore","SessionStore"],function(e){var t=e.CourseStore,n=e.ProgressStore,r=e.SessionStore;return{courseId:t.getCourseId(),branchId:r.getBranchId()||t.getCourseId(),courseSlug:t.getCourseSlug(),courseMaterials:t.getMaterials(),courseProgress:n.courseProgress}}),f.a)(E)}}]);