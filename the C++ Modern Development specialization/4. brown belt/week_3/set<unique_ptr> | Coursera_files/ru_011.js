(window.webpackJsonp=window.webpackJsonp||[]).push([[87],{"/epD":function(module,e,t){"use strict";var n=t("VbXa"),a=t.n(n),r=t("q1tI"),i=t.n(r),o=t("uhOI"),s=function(e){function LabLauncher(t){var n;return(n=e.call(this,t)||this).handleApiButtonClick=function(){var e;if(n.state.apiStatus!==o.a)return Promise.resolve();var t=window.open("","_blank"),a=function handleFailure(){return null==t||t.close(),n.resetApiStatusAfterDelay(),n.handleApiError(),n.setApiStatus(o.b)};return n.setApiStatus(o.c).then(function(){var e;return(0,n.props.getLaunchUrl)()}).then(function(e){var r=n.props,i=r.onLaunch,s=r.onComplete;if(e)return n.resetApiStatusAfterDelay(),t&&(t.location.href=e),null==i||i(e),null==s||s(),n.setApiStatus(o.d);a()},a).catch(a)},n.handleApiError=function(){var e=n.props,t=e.onError,a=e.onComplete;null==t||t(),null==a||a()},n.setApiStatus=function(e){return new Promise(function(t){n.setState({apiStatus:e},function(){t()})})},n.resetApiStatus=function(){clearTimeout(n.resetApiStatusTimeoutId),n.resetApiStatusTimeoutId=0,n.setApiStatus(o.a)},n.resetApiStatusAfterDelay=function(){var e=n.props.resetApiStatusDelay;n.resetApiStatusTimeoutId=setTimeout(n.resetApiStatus,e)},n.resetApiStatusTimeoutId=0,n.state={apiStatus:o.a,onClick:n.handleApiButtonClick},n}var t;return a()(LabLauncher,e),LabLauncher.prototype.render=function render(){var render=this.props.render;return render(this.state)},LabLauncher}(r.Component);s.defaultProps={resetApiStatusDelay:5e3},e.a=s},"33v5":function(module,e,t){"use strict";var n=t("VkAN"),a=t.n(n),r=t("AeFk"),i=t("q1tI"),o=t.n(i),s=t("fw5G"),c=t.n(s),u=t("763+"),l=t("8Hdl"),m=t("BBzL"),d=t.n(m);function _templateObject(){var e=a()(["\n    align-items: center;\n    border: 1px solid ",";\n    border-radius: ",";\n    display: flex;\n    justify-content: space-between;\n    padding: ",";\n  "]);return _templateObject=function _templateObject(){return e},e}var p=function container(e){return Object(r.c)(_templateObject(),e.palette.gray[500],e.spacing(4),e.spacing(12))},b=function ProgrammingDebugInfo(e){var t=e.courseId,n=e.courseSlug,a=e.itemId,i=e.className,o=Object(u.a)(),s=new c.a("/teach/".concat(n,"/grading/assignment-grading/").concat(a)).addQueryParam("versionId",t).toString();return Object(r.d)("div",{css:p(o),className:i},Object(r.d)(l.a,{variant:"body1"},d()("Debug tools")),Object(r.d)(l.a,{variant:"h4bold"},Object(r.d)("a",{href:s,target:"_blank",rel:"noopener noreferrer"},d()("View submissions for this assignment"))))};e.a=b},"50LF":function(module,exports,e){var t=e("X0H0"),n;"string"==typeof t&&(t=[[module.i,t,""]]);var a={transform:void 0},r=e("aET+")(t,a);t.locals&&(module.exports=t.locals)},"569g":function(module,e,t){"use strict";var n=t("VbXa"),a=t.n(n),r=t("q1tI"),i=t.n(r),o=t("kvW3"),s=t("8Hdl"),c=t("pH37"),u=t("KMW/"),l=t("q5zD"),m=t("us00"),d=t("RLfs"),p=t("BBzL"),b=t.n(p),g=t("50LF"),f=t.n(g),v=function(e){function Status(){return e.apply(this,arguments)||this}a()(Status,e);var t=Status.prototype;return t.shouldShowSkillTaggingDialog=function shouldShowSkillTaggingDialog(e,t){var n,a,r=!!u.a.get("Skills","SkillTaggingProgramming"),i="number"==typeof t&&"number"==typeof e&&e>=t,o=Object(c.a)(null===(n=this.props)||void 0===n?void 0:null===(a=n.computedItem)||void 0===a?void 0:a.courseId);return r&&i&&!o},t.renderLatePenalty=function renderLatePenalty(){var e=this.props.itemGrade;return i.a.createElement(m.a,{tooltipLabel:"Penalty of ".concat(100*e.getLatePenaltyRatio(),"% applied")})},t.renderTryAgain=function renderTryAgain(){var e=this.props,t=e.computedItem,n=t.isCumulativeGraded,a=t.isPassRequiredForCourse,r=e.learnerAssignment,s=e.itemGrade,c,u=e.submissionSummaries.find(function(e){return e.get("isBestSubmission")||e.get("isUsedForGrading")}),l=s.hasLatePenalty(),m=u&&u.get("score")||0,d=n&&a,p=n&&!a;return i.a.createElement("div",null,i.a.createElement("div",null,i.a.createElement(o.b,{message:b()("{status} · {bestScore, number}/{maxScore, number} points earned"),bestScore:m,status:p?b()("Graded"):b()("Try Again"),maxScore:null==r?void 0:r.maxScore}),l&&this.renderLatePenalty()),(!n||d)&&i.a.createElement("div",null,i.a.createElement(o.b,{message:b()("You must earn {passingScore}/{maxScore} points to pass."),passingScore:null==r?void 0:r.passingScore,maxScore:null==r?void 0:r.maxScore})))},t.renderStatus=function renderStatus(){var e=this.props,t=e.learnerAssignment,n=e.itemProgress,a=e.itemGrade,r=e.submissionSummaries,s=e.computedItem,c=s.isCumulativeGraded,u=s.isPassRequiredForCourse,m=s.courseId,p=s.id,g=c&&u,f=c&&!u;if(!r||!t)return null;var v=t.maxScore,O=t.passingScore,S=r.find(function(e){return e.get("isBestSubmission")||e.get("isUsedForGrading")}),h=a.hasLatePenalty(),j;if(S&&["Started","Completed"].includes(n.get("progressState")))return O&&S.get("score")>=O?i.a.createElement("div",null,this.shouldShowSkillTaggingDialog(S.get("score"),v)&&i.a.createElement(d.a,{courseId:m,itemId:p,dialogTitle:b()("Help us identify the right topics"),dialogDescription:b()("Select the skills that are covered in this assignment")}),(!c||g)&&i.a.createElement("span",{className:"is-used-for-grade-indicator"},i.a.createElement(l.a,{name:"check"})),i.a.createElement(o.b,{message:f?b()("Graded"):b()("Passed")}),i.a.createElement("span",null," · "),i.a.createElement(o.b,{message:b()("{score}/{maxScore} points"),score:S.get("score"),maxScore:v}),h&&this.renderLatePenalty()):this.renderTryAgain();return S&&O&&S.get("score")<O?this.renderTryAgain():!c||g?i.a.createElement(o.b,{message:b()("You have not submitted. You must earn {passingScore}/{maxScore} points to pass."),passingScore:O,maxScore:v}):b()("You have not submitted.")},t.render=function render(){return i.a.createElement(s.a,{variant:"body1"},this.renderStatus())},Status}(i.a.Component);e.a=v},"6Asy":function(module,e,t){"use strict";var n=t("lSNA"),a=t.n(n),r=t("q1tI"),i=t.n(r),o=t("vXr1"),s=t("sAJn"),c=t("U5zp"),u=t("mqQf"),l=t("uEzg"),m=t("6fvP"),d=t("XDtG"),p=t("9+hL"),b=t("2T3l"),g=t("6gca"),f=t.n(g),v="item_id",O=function ProgrammingNavigation(e){var t=e.courseId,n=e.courseSlug,g=e.itemId,v=e.children,O=Object(o.b)(),S,h=Object(o.e)().slug,j=Object(p.a)(n,g,h),I=Object(r.useCallback)(function(e){var t;O.push({name:e,params:(t={courseSlug:n},a()(t,"item_id",g),a()(t,"slug",h),t)})},[O,n,g,h]);return i.a.createElement(s.a,{value:j},i.a.createElement(c.a,{onChange:I},i.a.createElement(u.a,{label:f()("Instructions"),value:d.a.INSTRUCTIONS}),i.a.createElement(u.a,{label:f()("My submissions"),value:d.a.SUBMISSIONS}),Object(b.a)(t)||m.b.enabledResourcePanelToPublic()?i.a.createElement("div",null):i.a.createElement(u.a,{label:f()("Discussions"),value:d.a.DISCUSSIONS})),i.a.createElement(l.a,{value:j},v))};e.a=O},"9+hL":function(module,e,t){"use strict";t.d(e,"a",function(){return c});var n=t("lSNA"),a=t.n(n),r=t("vXr1"),i=t("XDtG"),o="item_id",s=function getCurrentSubView(e,t,n,r){var o,s=(o={},a()(o,"item_id",n),a()(o,"slug",r),a()(o,"courseSlug",t),o);return e.isActive({name:"programmingDefault",params:s},!0)||e.isActive({name:"programmingInstructions",params:s})?i.a.INSTRUCTIONS:e.isActive({name:"programmingSubmission",params:s})?i.a.SUBMISSIONS:i.a.DISCUSSIONS},c=function useCurrentSubView(e,t,n){var a=Object(r.b)();return s(a,e,t,n)}},J9Zm:function(module,e,t){"use strict";var n=t("VbXa"),a=t.n(n),r=t("q1tI"),i=t.n(r),o=t("ZJgU"),s=t("KXbA"),c=t("gNwb"),u=t("PamN"),l=t("NzvK"),m=t.n(l),d=t("pvU6"),p=t.n(d),b=Object(c.e)({type:"BUTTON"})(o.a),g=function(e){function LabSandboxLaunchButton(){for(var t,n=arguments.length,a=new Array(n),r=0;r<n;r++)a[r]=arguments[r];return(t=e.call.apply(e,[this].concat(a))||this).handleClick=function(){var e=t.props.courseSlug,n=Object(u.c)(e);window.open(n,"_blank")},t}var t;return a()(LabSandboxLaunchButton,e),LabSandboxLaunchButton.prototype.render=function render(){var e=this.props.isPrimaryCallToAction;return i.a.createElement("div",{className:"rc-LabSandboxLaunchButton"},i.a.createElement(b,{variant:e?"primary":"secondary",onClick:this.handleClick,trackingName:"lab_sandbox_launch_button",icon:i.a.createElement(s.a,{size:"medium",color:e?"invert":"default"}),size:"medium"},m()("Open Lab Sandbox")))},LabSandboxLaunchButton}(r.Component);e.a=g},MEI2:function(module,e,t){"use strict";t.d(e,"a",function(){return m});var n=t("VbXa"),a=t.n(n),r=t("q1tI"),i=t.n(r),o=t("BVC1"),s=t("KXbA"),c=t("su8M"),u=t("RWDQ"),l=t.n(u),m=function(e){function WorkspaceProgrammingSubmission(){for(var t,n=arguments.length,a=new Array(n),r=0;r<n;r++)a[r]=arguments[r];return(t=e.call.apply(e,[this].concat(a))||this).getLaunchUrl=function(){return new Promise(function(e){e(o.a.join(t.props.itemLink,"lab"))})},t}var t;return a()(WorkspaceProgrammingSubmission,e),WorkspaceProgrammingSubmission.prototype.render=function render(){var e=this.props.label;return i.a.createElement(c.a,{icon:i.a.createElement(s.a,{size:"medium",color:"invert"}),label:e||l()("Work in Browser"),size:"medium",variant:"primary",getLaunchUrl:this.getLaunchUrl,trackingName:"programming_lab_launch_button",role:"link"})},WorkspaceProgrammingSubmission}(r.Component)},NmOk:function(module,exports,e){},Oeft:function(module,e,t){"use strict";var n=t("q1tI"),a=t.n(n),r=function InteractiveIcon(e){var t=e.width,n=void 0===t?32:t,r=e.height,i=void 0===r?27:r;return a.a.createElement("svg",{width:n,height:i,viewBox:"0 0 24 20",fill:"none",xmlns:"http://www.w3.org/2000/svg"},a.a.createElement("path",{fillRule:"evenodd",clipRule:"evenodd",d:"M1.21875 4.48942H22.7812V1.13525H1.21875V4.48942ZM22.7812 5.20817H1.21875V18.8644H22.7812V5.20817ZM0.5 5.20817V4.48942V1.13525V0.416504H1.21875H22.7812H23.5V1.13525V4.48942V5.20817V18.8644V19.5832H22.7812H1.21875H0.5V18.8644V5.20817ZM3.85417 2.81234C3.85417 3.07697 3.63964 3.2915 3.375 3.2915C3.11036 3.2915 2.89583 3.07697 2.89583 2.81234C2.89583 2.5477 3.11036 2.33317 3.375 2.33317C3.63964 2.33317 3.85417 2.5477 3.85417 2.81234ZM5.29167 3.2915C5.5563 3.2915 5.77083 3.07697 5.77083 2.81234C5.77083 2.5477 5.5563 2.33317 5.29167 2.33317C5.02703 2.33317 4.8125 2.5477 4.8125 2.81234C4.8125 3.07697 5.02703 3.2915 5.29167 3.2915ZM7.6875 2.81234C7.6875 3.07697 7.47297 3.2915 7.20833 3.2915C6.9437 3.2915 6.72917 3.07697 6.72917 2.81234C6.72917 2.5477 6.9437 2.33317 7.20833 2.33317C7.47297 2.33317 7.6875 2.5477 7.6875 2.81234ZM13.1038 8.1893L10.2288 15.3768L10.8962 15.6437L13.7712 8.45624L13.1038 8.1893ZM8.95454 9.50162L9.45354 10.0189L7.48636 11.9165L9.45354 13.8141L8.95454 14.3314L6.4511 11.9165L8.95454 9.50162ZM15.1291 9.50616L17.5441 11.9211L15.0454 14.3314L14.5464 13.8141L16.5184 11.9119L14.6209 10.0144L15.1291 9.50616Z",fill:"#0056D2"}))};e.a=r},PLat:function(module,e,t){"use strict";t.r(e),t.d(e,"ProgrammingItem",function(){return U});var n=t("pVnL"),a=t.n(n),r=t("J4zp"),i=t.n(r),o=t("VbXa"),s=t.n(o),c=t("VkAN"),u=t.n(c),l=t("AeFk"),m=t("q1tI"),d=t.n(m),p=t("MnCE"),b=t("8cuT"),g=t("L1vm"),f=t("sQ/U"),v=t("8Hdl"),O=t("eJRr"),S=t.n(O),h=t("CsdX"),j=t("MEI2"),I=t("VXH7"),y=t("6Asy"),A=t("Q/rb"),C=t("njXA"),L=t("b1i5"),k=t("hbUA"),P=t("sprj"),w=t("R5lK"),N=t("33v5"),E=t("jYVy"),T=t("oLNK"),B=t("6O2X");function _templateObject5(){var e=u()(["\n    margin-bottom: ",";\n  "]);return _templateObject5=function _templateObject5(){return e},e}function _templateObject4(){var e=u()(["\n    margin: "," 0 ",";\n  "]);return _templateObject4=function _templateObject4(){return e},e}function _templateObject3(){var e=u()(["\n    margin: "," 0;\n\n    // Space between banners.\n    // The .banner class is necessary to get enough specificity to override base styles.\n    & > .banner + .banner {\n      margin-top: "," !important;\n    }\n  "]);return _templateObject3=function _templateObject3(){return e},e}function _templateObject2(){var e=u()(["\n    margin-bottom: ",";\n  "]);return _templateObject2=function _templateObject2(){return e},e}function _templateObject(){var e=u()(["\n    margin-bottom: ",";\n    "," {\n      margin-bottom: ",";\n    }\n  "]);return _templateObject=function _templateObject(){return e},e}var x=O.StyleSheet.create({labSandboxLauncher:{marginTop:24,marginBottom:40}}),D={title:function title(e){return Object(l.c)(_templateObject(),e.spacing(32),e.breakpoints.up("md"),e.spacing(48))},subtitleMargin:function subtitleMargin(e){return Object(l.c)(_templateObject2(),e.spacing(32))},bannerContainer:function bannerContainer(e){return Object(l.c)(_templateObject3(),e.spacing(32),e.spacing(16))},contentContainer:function contentContainer(e){return Object(l.c)(_templateObject4(),e.spacing(32),e.spacing(48))},launcherContainer:function launcherContainer(e){return Object(l.c)(_templateObject5(),e.spacing(48))}},U=function(e){function ProgrammingItem(){for(var t,n=arguments.length,a=new Array(n),r=0;r<n;r++)a[r]=arguments[r];return(t=e.call.apply(e,[this].concat(a))||this).state={learnerAssignment:null,labLauncher:null,showFirstAssignmentBanner:!0},t.handleFirstAssignmentAlertHidden=function(){t.setState({showFirstAssignmentBanner:!1})},t}s()(ProgrammingItem,e);var t=ProgrammingItem.prototype;return t.componentDidMount=function componentDidMount(){this.fetchData()},t.fetchData=function fetchData(){var e=this,t=this.props,n=t.courseId,a=t.courseSlug,r=t.computedItem,o=r.id,s=r.contentSummary.typeName,c=Promise.resolve(null);"programming"!==s&&(c=Promise.resolve(Object(E.a)({itemId:o,courseId:n,courseSlug:a})));var u=Promise.resolve(null);["gradedProgramming","ungradedProgramming"].includes(s)&&(u=Promise.resolve(T.a.load({userId:f.a.get().id,courseId:n,courseSlug:a,itemId:o,itemTypeName:s}))),Promise.all([c,u]).then(function(t){var a,r=i()(t,1)[0],s;return"workspace"===(null==r?void 0:r.submissionBuilderSchema.get("typeName"))?Promise.resolve(Object(L.i)(n,o)).then(function(t){e.setState({learnerAssignment:r,labLauncher:t})}):Promise.resolve().then(function(){e.setState({learnerAssignment:r})})})},t.render=function render(){var e=this.props,t=e.computedItem,n=e.courseId,r=e.courseSlug,i=e.itemMetadata,o=e.children,s=this.state,c=s.learnerAssignment,u=s.labLauncher,m=s.showFirstAssignmentBanner,p=t.id,b=t.contentSummary.typeName,g=t.name,f=B.a.hasAdminPrivileges(),O=f||m,S=["gradedProgramming","ungradedProgramming"].includes(b);return Object(l.d)(A.a,{courseId:n,feedbackType:"programming",computedItem:t},Object(l.d)("header",null,Object(l.d)(v.a,{variant:"d2",component:"h1",css:D.title},Object(k.f)(t),": ",g),S&&Object(l.d)("div",{css:!O&&D.subtitleMargin},Object(l.d)(P.a,{computedItem:t,itemMetadata:i,learnerAssignment:c})),O&&Object(l.d)("div",{css:D.bannerContainer},f&&Object(l.d)(N.a,{className:"banner",courseId:n,courseSlug:r,itemId:p}),m&&Object(l.d)(w.a,{className:"banner",courseSlug:r,itemId:p,onHidden:this.handleFirstAssignmentAlertHidden})),Object(l.d)(I.a,{computedItem:t}),u?Object(l.d)("div",{css:D.launcherContainer},Object(l.d)(j.a,{courseId:u.courseId,itemId:u.itemId,itemLink:i.getBaseLink(),label:u.label})):Object(l.d)(C.a,a()({},Object(h.d)(x.labSandboxLauncher),{courseId:n,itemId:p,showFeedbackLink:!0}))),Object(l.d)(y.a,{courseId:n,courseSlug:r,itemId:p},o&&Object(l.d)("div",{css:D.contentContainer},d.a.cloneElement(o,{itemMetadata:i}))))},ProgrammingItem}(d.a.Component);e.default=Object(p.compose)(Object(b.a)(["CourseStore"],function(e){var t=e.CourseStore;return{courseId:t.getCourseId(),courseSlug:t.getCourseSlug()}}),g.a.createTrackedContainer(function(e){var t,n;return{namespace:{app:"open_course_item",page:"programming_assignment_page"},open_course_id:e.courseId,item_id:e.computedItem.id}}))(U)},"Q/rb":function(module,e,t){"use strict";var n=t("VkAN"),a=t.n(n),r=t("q1tI"),i=t.n(r),o=t("AeFk"),s=t("763+"),c=t("YmkS"),u=t("WN9/"),l=t.n(u);function _templateObject2(){var e=a()(["\n    border-top: 1px solid #ddd;\n    padding: 15px 0;\n  "]);return _templateObject2=function _templateObject2(){return e},e}function _templateObject(){var e=a()(["\n    max-width: 960px;\n    color: #1f1f1f;\n\n    margin-top: ",";\n    "," {\n      margin-top: ",";\n    }\n    "," {\n      margin-top: ",";\n    }\n  "]);return _templateObject=function _templateObject(){return e},e}var m=function ItemBox(e){var t=e.className,n=e.computedItem,a=e.feedbackType,r=e.hideFeedback,i=e.children,u=Object(s.a)(),l=Object(o.c)(_templateObject(),u.spacing(24),u.breakpoints.up("sm"),u.spacing(32),u.breakpoints.up("md"),u.spacing(48)),m=Object(o.c)(_templateObject2());return Object(o.d)("div",null,Object(o.d)("div",{className:t,css:l},i,!r&&n&&a&&Object(o.d)("div",{css:m},Object(o.d)(c.a,{computedItem:n,itemFeedbackType:a}))))};e.a=m},R5lK:function(module,e,t){"use strict";var n=t("J4zp"),a=t.n(n),r=t("q1tI"),i=t.n(r),o=t("MnCE"),s=t("ZJgU"),c=t("HulD"),u=t("gNwb"),l=t("u5mk"),m=t("emlC"),d=t("SvHW"),p=t("XRUg"),b=t("BBzL"),g=t.n(b),f=Object(u.e)({type:"BUTTON"})(s.a),v=function ProgrammingAssignmentInformation(e){var t=e.isFirstProgrammingAssignment,n=e.courseSlug,o=e.onHidden,s=e.className,u=e.replaceCustomContent,l=Object(r.useState)(!1),m=a()(l,2),b=m[0],v=m[1],O=Object(r.useState)(!1),S=a()(O,2),h=S[0],j=S[1],I=Object(r.useCallback)(function(){return j(!0)},[]),y=Object(r.useCallback)(function(){return j(!1)},[]),A=Object(r.useCallback)(function(e){v(!0),e()},[]);if(!t)return b||(v(!0),null==o||o()),null;return i.a.createElement(i.a.Fragment,null,i.a.createElement(p.a,{storageKey:"seen-prog-".concat(n)},function(e){var t=e.hideForever;return i.a.createElement(c.a,{className:s,severity:"information",title:g()("First programming assignment"),inlineAction:i.a.createElement(f,{trackingName:"show_programming_information","aria-label":g()("Learn more about programming assignments"),variant:"ghost",size:"small",onClick:I},g()("Learn more")),onDismiss:function onDismiss(){return A(t)}},i.a.createElement("div",null,u(g()("This is your first programming assignment for this #{course}."),{returnsString:!0})))}),h&&i.a.createElement(d.a,{onClose:y}))};e.a=Object(o.compose)(Object(m.a)(["CourseStore"],function(e,t){var n=e.CourseStore,a=t.itemId;return{isFirstProgrammingAssignment:n.isFirstProgrammingAssignment(a)}}),l.a)(v)},RWDQ:function(module,exports,e){var t=e("i0ok"),n=t.default?t.default:{},a,r=(0,e("HdzH").default)(n);r.getLocale=function(){return"ru"},module.exports=r},SvHW:function(module,e,t){"use strict";var n=t("VkAN"),a=t.n(n),r=t("AeFk"),i=t("q1tI"),o=t.n(i),s=t("763+"),c=t("6/Gu"),u=t("8Hdl"),l=t("ZJgU"),m=t("JPjw"),d=t("BBzL"),p=t.n(d);function _templateObject6(){var e=a()(["\n    margin-top: ",";\n  "]);return _templateObject6=function _templateObject6(){return e},e}function _templateObject5(){var e=a()(["\n    margin-top: ",";\n    margin-bottom: ",";\n  "]);return _templateObject5=function _templateObject5(){return e},e}function _templateObject4(){var e=a()(["\n    margin-top: ",";\n  "]);return _templateObject4=function _templateObject4(){return e},e}function _templateObject3(){var e=a()(["\n    margin-bottom: ",";\n  "]);return _templateObject3=function _templateObject3(){return e},e}function _templateObject2(){var e=a()(["\n    text-align: left;\n  "]);return _templateObject2=function _templateObject2(){return e},e}function _templateObject(){var e=a()(["\n    max-width: 568px;\n    width: auto;\n  "]);return _templateObject=function _templateObject(){return e},e}var b={modal:Object(r.c)(_templateObject()),container:Object(r.c)(_templateObject2()),title:function title(e){return Object(r.c)(_templateObject3(),e.spacing(32))},faqSubtitle:function faqSubtitle(e){return Object(r.c)(_templateObject4(),e.spacing(24))},subheading:function subheading(e){return Object(r.c)(_templateObject5(),e.spacing(16),e.spacing(16))},closeButton:function closeButton(e){return Object(r.c)(_templateObject6(),e.spacing(48))}},g=function AssignmentInformationModal(e){var t=e.onClose,n=Object(s.a)();return Object(r.d)(m.a,{modalName:"Programming Assignment Information",allowClose:!0,onRequestClose:t,css:b.modal},Object(r.d)(c.a,{css:b.container},Object(r.d)(u.a,{css:b.title(n),variant:"h1semibold"},p()("Programming assignments")),Object(r.d)(u.a,{variant:"body1"},p()("Programming assignments require you to write and run a computer program to solve a problem.")),Object(r.d)(u.a,{css:b.faqSubtitle(n),variant:"h3semibold"},p()("Frequently asked questions:")),Object(r.d)(u.a,{css:b.subheading(n),variant:"h3bold"},p()("What are programming assignments?")),Object(r.d)(u.a,{variant:"body1"},p()("Programming assignments include both assignment instructions and assignment parts. Instructions may include a link to a downloadable starter package that includes starter code, detailed guidelines, and other resources. Assignment parts are similar to individual quiz questions. Each part is a single coding task that can be completed one at a time.")),Object(r.d)(u.a,{css:b.subheading(n),variant:"h3bold"},p()("How are programming assignments graded?")),Object(r.d)(u.a,{variant:"body1"},p()("Programming assignments are graded automatically. If they use a built-in-algorithm you’ll see your grade within seconds. If they use a custom grader, you may need to wait up to an hour.")),Object(r.d)(u.a,{css:b.subheading(n),variant:"h3bold"},p()("Can I resubmit a programming assignment?")),Object(r.d)(u.a,{variant:"body1"},p()("You can resubmit all programming assignments to improve your grade. Follow the same steps as submitting a new assignment.")),Object(r.d)(u.a,{css:b.subheading(n),variant:"h3bold"},p()("What do I do if I have trouble submitting my assignment?")),Object(r.d)(u.a,{variant:"body1"},p()("If you have trouble submitting your assignment, we encourage you to visit your course Discussion Forums as many of your peers are likely to have had similar problems and have found a solution. Each programming assignment has its own sub-forum to discuss with peers.")),Object(r.d)(l.a,{css:b.closeButton(n),variant:"primary",size:"medium",onClick:t},p()("Close"))))};e.a=g},TSwX:function(module,e,t){"use strict";var n=t("pVnL"),a=t.n(n),r=t("QILm"),i=t.n(r),o=t("AeFk"),s=t("q1tI"),c=t.n(s),u=t("763+"),l=t("ZJgU"),m=t("/szJ"),d=t("um/3"),p=t("uhOI"),b=t("8WNh"),g=function getIconSizeFromButtonSize(e){return e},f=function getIconFromApiStatus(e,t,n){return"API_IN_PROGRESS"===e?Object(o.d)(b.a,{color:n.palette.blue[600],size:"medium"===t?20:16}):"API_SUCCESS"===e?Object(o.d)(m.a,{size:t,color:"success"}):"API_ERROR"===e?Object(o.d)(d.a,{size:t,color:"error"}):void 0},v=function getIsDisabledFromApiStatus(e){return"API_BEFORE_SEND"!==e},O=function getStyleFromApiStatus(e,t){var n="transparent !important";return"API_SUCCESS"===e?Object(o.c)({backgroundColor:n,boxShadow:"inset 0 0 0 1px ".concat(t.palette.green[700]," !important"),color:"".concat(t.palette.green[700]," !important")}):"API_ERROR"===e?Object(o.c)({backgroundColor:n,boxShadow:"inset 0 0 0 1px ".concat(t.palette.red[700]," !important"),color:"".concat(t.palette.red[700]," !important")}):"API_IN_PROGRESS"===e?Object(o.c)({backgroundColor:n,boxShadow:"inset 0 0 0 1px ".concat(t.palette.gray[400]," !important"),color:"".concat(t.palette.gray[400]," !important")}):null},S=function ApiButton(e){var t=e.children,n=e.label,r=e.disabled,s=e.apiStatus,c=void 0===s?p.a:s,m=e.variant,d=void 0===m?"secondary":m,b=e.size,S=void 0===b?"medium":b,h=e.iconPosition,j=void 0===h?"before":h,I=i()(e,["children","label","disabled","apiStatus","variant","size","iconPosition"]),y=Object(u.a)(),A=g(S),C=f(c,A,y)||t,L=O(c,y),k=null!=r?r:v(c),P="API_BEFORE_SEND"!==c;return Object(o.d)(l.a,a()({css:L,variant:d,size:S,iconPosition:j,icon:C,disabled:k},I),Object(o.d)("div",{"aria-live":P?"polite":"off"},n))};e.a=S},VXH7:function(module,e,t){"use strict";var n=t("VkAN"),a=t.n(n),r=t("AeFk"),i=t("q1tI"),o=t.n(i),s=t("wd/R"),c=t.n(s),u=t("MnCE"),l=t("8cuT"),m=t("kvW3"),d=t("763+"),p=t("6/Gu"),b=t("8Hdl"),g=t("u5mk"),f=t("hbUA"),v=t("BBzL"),O=t.n(v);function _templateObject(){var e=a()(["\n    "," {\n      margin-bottom: ",";\n    }\n\n    "," {\n      margin-bottom: ",";\n    }\n  "]);return _templateObject=function _templateObject(){return e},e}var S=function container(e){return Object(r.c)(_templateObject(),e.breakpoints.up("md"),e.spacing(16),e.breakpoints.down("sm"),e.spacing(24))},h=function ProgrammingDeadline(e){var t=e.computedItem,n=t.deadline,a=t.isCumulativeGraded,i=e.isEnrolled,s=e.replaceCustomContent,u=Object(d.a)();if(!n||!i)return null;var l=c()().isAfter(n),g=Object(f.a)(n);return Object(r.d)(p.a,{container:!0,css:S(u),spacing:8},Object(r.d)(p.a,{item:!0,xs:12,sm:"auto"},Object(r.d)(b.a,{component:"h2",variant:"h3bold"},O()("Deadline"))),Object(r.d)(p.a,{item:!0},l?Object(r.d)(o.a.Fragment,null,Object(r.d)(b.a,{variant:"body1"},Object(r.d)(m.b,{message:O()("The assignment was due on {deadline}"),deadline:g})),!a&&Object(r.d)(b.a,{variant:"body1"},s(O()("You can still pass this assignment before the #{course} ends."),{returnsString:!0}))):Object(r.d)(b.a,{variant:"body1"},Object(r.d)(m.b,{message:O()("Pass this assignment by {deadline}"),deadline:g}))))};e.a=Object(u.compose)(Object(l.a)(["SessionStore"],function(e){var t;return{isEnrolled:e.SessionStore.isEnrolled()}}),g.a)(h)},X0H0:function(module,exports,e){},XDtG:function(module,e,t){"use strict";t.d(e,"a",function(){return n});var n={INSTRUCTIONS:"programmingInstructions",SUBMISSIONS:"programmingSubmission",DISCUSSIONS:"programming.discussions"}},XRUg:function(module,e,t){"use strict";var n=t("J4zp"),a=t.n(n),r=t("q1tI"),i=t.n(r),o=t("IWWe"),s=!0,c=function createFullStorageKey(e){var t=!(arguments.length>1&&void 0!==arguments[1])||arguments[1];return t?"shown-once:".concat(e):e},u=function loadShown(e){var t=function deserialize(e){return"true"===e},n=!1,a=!1,r=!1;return o.a.getItem(e,t,!1,!1,!1)},l=function saveShown(e){var t=!0,n=function serialize(e){return e.toString()},a=!1;o.a.setItem(e,!0,n,!1)},m=function ShowOnce(e){var t=e.storageKey,n=e.children,i=e.addPrefix,o,s=c(t,void 0===i||i),m=Object(r.useState)(function(){return!u(s)}),d=a()(m,2),p=d[0],b=d[1],g=Object(r.useCallback)(function(){l(s),b(!1)},[s]);if(!p)return null;return n({hideForever:g})};e.a=m},i0ok:function(module,exports){exports.default={"Work in Browser":"Работать в браузере"}},njXA:function(module,e,t){"use strict";var n=t("VkAN"),a=t.n(n),r=t("AeFk"),i=t("q1tI"),o=t.n(i),s=t("MnCE"),c=t("8cuT"),u=t("+LJP"),l=t("kvW3"),m=t("6/Gu"),d=t("8Hdl"),p=t("G2Rf"),b=t("Oeft"),g=t("J9Zm"),f=t("nvAn"),v=t("PamN"),O=t("sOkY"),S=t("NzvK"),h=t.n(S);function _templateObject5(){var e=a()(["\n    margin-bottom: ",";\n    padding-left: ",";\n  "]);return _templateObject5=function _templateObject5(){return e},e}function _templateObject4(){var e=a()(["\n    background-color: ",";\n    border-radius: 4px;\n    color: ",";\n    padding: 2px ",";\n    text-transform: uppercase;\n  "]);return _templateObject4=function _templateObject4(){return e},e}function _templateObject3(){var e=a()(["\n    margin: 0 ",";\n  "]);return _templateObject3=function _templateObject3(){return e},e}function _templateObject2(){var e=a()(["\n    margin-bottom: ",";\n  "]);return _templateObject2=function _templateObject2(){return e},e}function _templateObject(){var e=a()(["\n    border: 1px solid #eaeaea;\n    padding: ",";\n  "]);return _templateObject=function _templateObject(){return e},e}var j={container:function container(e){return Object(r.c)(_templateObject(),e.spacing(24))},headerBar:function headerBar(e){return Object(r.c)(_templateObject2(),e.spacing(12))},header:function header(e){return Object(r.c)(_templateObject3(),e.spacing(12))},betaLabel:function betaLabel(e){return Object(r.c)(_templateObject4(),e.palette.black[500],e.palette.white,e.spacing(4))},descriptionList:function descriptionList(e){return Object(r.c)(_templateObject5(),e.spacing(24),e.spacing(24))}},I=function LabSandboxLauncher(e){var t=e.courseId,n=e.courseSlug,a=e.courseBranchId,i=e.itemId,o=e.ownsCourse,s=e.isFreeTrial,c=e.className,u=e.style,p=e.isPrimaryCallToAction,S=void 0===p||p;if(!Object(v.b)(t,a,i,o,s))return null;var I=Object(f.a)(t),y=Object(v.d)(null==I?void 0:I.computerLanguages,null==I?void 0:I.computerLanguagesAreProgrammingLanguages),A=null==I?void 0:I.labApplicationName;return Object(r.d)(O.a,{"data-e2e":"LabSandboxLauncher",trackingName:"lab_sandbox_launcher",withVisibilityTracking:!0,trackClicks:!1,css:j.container,className:c,style:u},Object(r.d)(m.a,{container:!0,css:j.headerBar,alignItems:"center"},Object(r.d)(b.a,null),Object(r.d)(d.a,{css:j.header,variant:"h3semibold"},h()("Coursera Lab Sandbox")),Object(r.d)(d.a,{css:j.betaLabel,variant:"h4bold"},h()("Beta"))),Object(r.d)("ul",{css:j.descriptionList},Object(r.d)("li",null,Object(r.d)(d.a,{variant:"body1"},Object(r.d)(l.b,{message:h()("Easily launch Coursera's preconfigured environment for {languages}"),languages:y}))),A?Object(r.d)("li",null,Object(r.d)(d.a,{variant:"body1"},Object(r.d)(l.b,{message:h()("Get access to all dependencies (libraries and packages) for {labApplication}—no local software installation required"),labApplication:A}))):Object(r.d)("li",null,Object(r.d)(d.a,{variant:"body1"},Object(r.d)(l.b,{message:h()("Get access to all development dependencies (libraries and packages)—no local software installation required")}))),Object(r.d)("li",null,Object(r.d)(d.a,{variant:"body1"},Object(r.d)(l.b,{message:h()("Practice {languages}, run test cases, and work on assignments from your browser"),languages:y})))),Object(r.d)(g.a,{courseSlug:n,isPrimaryCallToAction:S}))};e.a=Object(s.compose)(Object(u.a)(function(e){return{courseSlug:e.params.courseSlug}}),Object(c.a)(["CourseStore","SessionStore"],function(e){var t=e.CourseStore,n;return{courseBranchId:e.SessionStore.getBranchId()||t.getCourseId()}}),p.a)(I)},oLNK:function(module,e,t){"use strict";var n=t("F/us"),a=t.n(n),r=t("+203"),i=t.n(r),o=t("HpDP");function onLoadSuccess(e){s.submissionSummaries=e,s.emit("update",e)}function onLoadError(e){s.error=e,s.emit("updateError",e)}function SubmissionSummariesStore(){this.submissionSummaries=null}SubmissionSummariesStore.prototype=a.a.extend({},i.a.prototype,{load:function load(e){var t=e.itemId,n=e.itemTypeName,a=e.courseId,r=e.courseSlug,i=e.userId;Object(o.a)({itemId:t,itemTypeName:n,courseId:a,courseSlug:r,userId:i}).then(onLoadSuccess,onLoadError).done()}});var s=new SubmissionSummariesStore;e.a=s},pvU6:function(module,exports,e){var t=e("NmOk"),n;"string"==typeof t&&(t=[[module.i,t,""]]);var a={transform:void 0},r=e("aET+")(t,a);t.locals&&(module.exports=t.locals)},sprj:function(module,e,t){"use strict";var n=t("VbXa"),a=t.n(n),r=t("q1tI"),i=t.n(r),o=t("8cuT"),s=t("hbUA"),c=t("569g"),u=t("oLNK"),l=function(e){function MetaInfoArea(t,n){var a;return(a=e.call(this,t,n)||this).onProgressChange=function(){a.setState(a.getState())},a.onSubmissionSummariesUpdate=function(){a.setState(a.getState())},a.state=a.getState(),a}a()(MetaInfoArea,e);var t=MetaInfoArea.prototype;return t.componentDidMount=function componentDidMount(){var e=this.props.courseProgress;e&&e.on("refreshed",this.onProgressChange),u.a&&u.a.on("update",this.onSubmissionSummariesUpdate)},t.componentWillUnmount=function componentWillUnmount(){var e=this.props.courseProgress;e&&e.off("refreshed",this.onProgressChange),u.a.removeListener("update",this.onSubmissionSummariesUpdate)},t.getState=function getState(){var e=this.props,t=e.itemMetadata,n=e.courseProgress,a=e.itemGrade,r=t.get("id");return{itemGrade:a,itemProgress:n&&n.getItemProgress(r),submissionSummaries:u.a.submissionSummaries}},t.render=function render(){var e=this.props,t=e.computedItem,n=e.learnerAssignment,a=this.state,r=a.itemProgress,o=a.itemGrade,u=a.submissionSummaries;if(!(r&&o&&Object(s.z)(t)))return null;return i.a.createElement(c.a,{computedItem:t,learnerAssignment:n,itemProgress:r,itemGrade:o,submissionSummaries:u})},MetaInfoArea}(i.a.Component);e.a=Object(o.a)(["VerificationStore","ProgressStore","CourseViewGradeStore"],function(e,t){var n=e.VerificationStore,a=e.ProgressStore,r=e.CourseViewGradeStore,i=t.itemMetadata;return{courseProgress:a.courseProgress,verificationDisplay:n.getVerificationDisplay(),itemGrade:r.getItemGrade(i.getId())}})(l)},su8M:function(module,e,t){"use strict";var n=t("lSNA"),a=t.n(n),r=t("q1tI"),i=t.n(r),o=t("w/1P"),s=t.n(o),c=t("uhOI"),u=t("gNwb"),l=t("/epD"),m=t("TSwX"),d=t("BBzL"),p=t.n(d),b=Object(u.e)({type:"BUTTON"})(m.a),g=function getApiButtonLabel(e,t,n){var r,i;return(r={},a()(r,c.a,n||(t?p()("Open #{appName}",{appName:t}):p()("Open"))),a()(r,c.c,p()("Opening...")),a()(r,c.d,t?p()("Opened #{appName}",{appName:t}):p()("Opened")),a()(r,c.b,t?p()("Error opening #{appName}",{appName:t}):p()("Error")),r)[e]},f=function WorkspaceButton(e){var t=e.className,n=e.getLaunchUrl,a=e.resetApiStatusDelay,r=e.appName,o=e.label,c=e.icon,u=e.variant,m=e.size,d=e.role,p=void 0===d?"button":d,f=e.trackingName,v=void 0===f?"workspace_launch_button":f;return i.a.createElement("div",{className:s()(t)},i.a.createElement(l.a,{getLaunchUrl:n,resetApiStatusDelay:a,render:function render(e){var t=e.apiStatus,n=e.onClick;return i.a.createElement(b,{label:g(t,r,o),variant:u,onClick:n,apiStatus:t,size:m,trackingName:v,iconPosition:"after",role:p},c)}}))};e.a=f}}]);