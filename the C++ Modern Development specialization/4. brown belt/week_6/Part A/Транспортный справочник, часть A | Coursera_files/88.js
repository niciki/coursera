(window.webpackJsonp=window.webpackJsonp||[]).push([[88],{"/epD":function(module,e,t){"use strict";var n=t("VbXa"),r=t.n(n),a=t("q1tI"),o=t.n(a),i=t("uhOI"),s=function(e){function LabLauncher(t){var n;return(n=e.call(this,t)||this).handleApiButtonClick=function(){var e;if(n.state.apiStatus!==i.a)return Promise.resolve();var t=window.open("","_blank"),r=function handleFailure(){return null==t||t.close(),n.resetApiStatusAfterDelay(),n.handleApiError(),n.setApiStatus(i.b)};return n.setApiStatus(i.c).then(function(){var e;return(0,n.props.getLaunchUrl)()}).then(function(e){var a=n.props,o=a.onLaunch,s=a.onComplete;if(e)return n.resetApiStatusAfterDelay(),t&&(t.location.href=e),null==o||o(e),null==s||s(),n.setApiStatus(i.d);r()},r).catch(r)},n.handleApiError=function(){var e=n.props,t=e.onError,r=e.onComplete;null==t||t(),null==r||r()},n.setApiStatus=function(e){return new Promise(function(t){n.setState({apiStatus:e},function(){t()})})},n.resetApiStatus=function(){clearTimeout(n.resetApiStatusTimeoutId),n.resetApiStatusTimeoutId=0,n.setApiStatus(i.a)},n.resetApiStatusAfterDelay=function(){var e=n.props.resetApiStatusDelay;n.resetApiStatusTimeoutId=setTimeout(n.resetApiStatus,e)},n.resetApiStatusTimeoutId=0,n.state={apiStatus:i.a,onClick:n.handleApiButtonClick},n}var t;return r()(LabLauncher,e),LabLauncher.prototype.render=function render(){var render=this.props.render;return render(this.state)},LabLauncher}(a.Component);s.defaultProps={resetApiStatusDelay:5e3},e.a=s},"4+Xa":function(module,e,t){"use strict";var n=t("K7Vu"),r="onDemandProgrammingTokens.v1",a={get:function get(e){var t=e.itemId,a=e.courseId,o=e.courseSlug,i;return new n.a({itemId:t,courseId:a,courseSlug:o}).getWithCourseItemId(r)},newToken:function newToken(e){var t=e.itemId,a=e.courseId,o=e.courseSlug,i,s=null,c={courseId:a,itemId:t};return new n.a({itemId:t,courseId:a,courseSlug:o}).create(r,c,null,!1)}};e.a=a;var o=a.get,i=a.newToken},"4b+W":function(module,e,t){"use strict";var n=t("fw5G"),r=t.n(n),a=t("PDuk"),o=t("LeYt");e.a=function(e){var t=e.courseId,n=e.itemId,i=a.a.tupleToStringKey([t,n]),s=new r.a(i);return o.a.get(s.toString())}},"7mPg":function(module,e,t){"use strict";t.d(e,"a",function(){return g}),t.d(e,"b",function(){return b});var n=t("fw5G"),r=t.n(n),a=t("S+eF"),o=t.n(a),i=t("DnuM"),s=t("PDuk"),c=t("sQ/U"),u=Object(i.a)("/api/workspaceMetadata.v1",{type:"rest"}),l=Object(i.a)("/api/workspaceLaunch.v1",{type:"rest"}),d=function checkedPromise(e){return o()(e).done(),e},m=function getWorkspace(e,t){var n=(new r.a).addQueryParam("q","user").addQueryParam("userId",String(e)).addQueryParam("templateId",t);return d(o()(u.get(n.toString())).then(function(e){return e&&e.elements&&e.elements[0]}))},p=function createWorkspace(e,t){var n=new r.a,a={templateId:t,owners:[e],publishDestinations:[]};return d(o()(u.post(n.toString(),{data:a})).then(function(e){return e&&e.elements&&e.elements[0]}))},g=function getOrCreateWorkspace(e,t){return d(m(e,t).then(function(n){return n||p(e,t)}))},b=function getWorkspaceLaunchUrl(e,t){var n=Object(s.c)([c.a.get().id,e]),a=(new r.a).addQueryParam("action","launch").addQueryParam("userWorkspaceId",n).addQueryParam("itemId",t);return d(o()(l.post(a.toString())))}},GjXZ:function(module,e,t){"use strict";var n=t("VkAN"),r=t.n(n),a=t("AeFk"),o=t("q1tI"),i=t.n(o),s=t("7GkZ"),c=t("qenF"),u=t("nfyY"),l=t("zlL2"),d=t("teQO"),m=t("d/m/"),p=t("uMx8"),g=t("BBzL"),b=t.n(g);function _templateObject(){var e=r()(["\n    margin-top: ",";\n  "]);return _templateObject=function _templateObject(){return e},e}var f={submissionInstructionsBox:function submissionInstructionsBox(e){return Object(a.c)(_templateObject(),e.spacing(32))}},h=function Instructions(e){var t=e.instructions,n=e.itemMetadata,r=e.labLauncher,o=e.learnerAssignment,i=n.get("course.id"),g=n.get("id"),h=Object(p.a)(i,g),v=n.getTypeName(),O=Object(p.b)(i,g),k="programming"===v,j=("gradedProgramming"===v||"ungradedProgramming"===v)&&"script"===(null==o?void 0:o.submissionBuilderSchema.get("typeName")),I,S=!k&&!j&&!(O||r);return Object(a.d)("div",null,t&&Object(a.d)(s.a,{cml:t.get("assignmentInstructions"),isCdsEnabled:Object(c.g)()}),Object(a.d)("div",{css:f.submissionInstructionsBox},h&&h.templateId&&Object(a.d)(m.a,{templateId:h.templateId,itemId:g}),k&&Object(a.d)(d.a,{itemMetadata:n}),j&&Object(a.d)(u.a,{itemMetadata:n}),S&&Object(a.d)(l.a,{instructions:Object(a.d)("div",null,b()('When you\'re ready to submit, you can upload files for each part of the assignment on the "My submissions" tab.'))})))};e.a=h},LMJJ:function(module,e,t){"use strict";var n=t("sQ/U"),r=t("K7Vu"),a="onDemandProgrammingGradedScriptTokens.v1",o={get:function get(e){var t=e.itemId,n=e.courseId,o=e.courseSlug,i;return new r.a({itemId:t,courseId:n,courseSlug:o}).getWithUserCourseItemId(a,{fields:["secret","issuedTo","issuedAt","expiresAt"]})},newToken:function newToken(e){var t=e.itemId,o=e.courseId,i=e.courseSlug,s=e.verifiableId,c=new r.a({itemId:t,courseId:o,courseSlug:i}),u=null,l={courseId:o,itemId:t,learnerId:n.a.get().id,verifiableId:s||null};return c.create(a,l,null,!1)}};e.a=o;var i=o.get,s=o.newToken},LeYt:function(module,e,t){"use strict";var n=t("TSOT");e.a=Object(n.a)("/api/onDemandProgrammingImmediateInstructions.v1/",{type:"rest"})},OAHX:function(module,e,t){"use strict";var n=t("sQ/U"),r=t("K7Vu"),a="onDemandProgrammingUngradedScriptTokens.v1",o={get:function get(e){var t=e.itemId,n=e.courseId,o=e.courseSlug,i;return new r.a({itemId:t,courseId:n,courseSlug:o}).getWithUserCourseItemId(a,{fields:["secret","issuedTo","issuedAt","expiresAt"]})},newToken:function newToken(e){var t=e.itemId,o=e.courseId,i=e.courseSlug,s=new r.a({itemId:t,courseId:o,courseSlug:i}),c=null,u={courseId:o,itemId:t,learnerId:n.a.get().id};return s.create(a,u,null,!1)}};e.a=o;var i=o.get,s=o.newToken},TSwX:function(module,e,t){"use strict";var n=t("pVnL"),r=t.n(n),a=t("QILm"),o=t.n(a),i=t("AeFk"),s=t("q1tI"),c=t.n(s),u=t("763+"),l=t("ZJgU"),d=t("/szJ"),m=t("um/3"),p=t("uhOI"),g=t("8WNh"),b=function getIconSizeFromButtonSize(e){return e},f=function getIconFromApiStatus(e,t,n){return"API_IN_PROGRESS"===e?Object(i.d)(g.a,{color:n.palette.blue[600],size:"medium"===t?20:16}):"API_SUCCESS"===e?Object(i.d)(d.a,{size:t,color:"success"}):"API_ERROR"===e?Object(i.d)(m.a,{size:t,color:"error"}):void 0},h=function getIsDisabledFromApiStatus(e){return"API_BEFORE_SEND"!==e},v=function getStyleFromApiStatus(e,t){var n="transparent !important";return"API_SUCCESS"===e?Object(i.c)({backgroundColor:n,boxShadow:"inset 0 0 0 1px ".concat(t.palette.green[700]," !important"),color:"".concat(t.palette.green[700]," !important")}):"API_ERROR"===e?Object(i.c)({backgroundColor:n,boxShadow:"inset 0 0 0 1px ".concat(t.palette.red[700]," !important"),color:"".concat(t.palette.red[700]," !important")}):"API_IN_PROGRESS"===e?Object(i.c)({backgroundColor:n,boxShadow:"inset 0 0 0 1px ".concat(t.palette.gray[400]," !important"),color:"".concat(t.palette.gray[400]," !important")}):null},O=function ApiButton(e){var t=e.children,n=e.label,a=e.disabled,s=e.apiStatus,c=void 0===s?p.a:s,d=e.variant,m=void 0===d?"secondary":d,g=e.size,O=void 0===g?"medium":g,k=e.iconPosition,j=void 0===k?"before":k,I=o()(e,["children","label","disabled","apiStatus","variant","size","iconPosition"]),S=Object(u.a)(),y=b(O),T=f(c,y,S)||t,A=v(c,S),w=null!=a?a:h(c),C="API_BEFORE_SEND"!==c;return Object(i.d)(l.a,r()({css:A,variant:m,size:O,iconPosition:j,icon:T,disabled:w},I),Object(i.d)("div",{"aria-live":C?"polite":"off"},n))};e.a=O},TUZB:function(module,e,t){"use strict";t.r(e),t.d(e,"ProgrammingInstructions",function(){return d});var n=t("VbXa"),r=t.n(n),a=t("q1tI"),o=t.n(a),i=t("8WNh"),s=t("b1i5"),c=t("GjXZ"),u=t("X6TH"),l=t("jYVy"),d=function(e){function ProgrammingInstructions(){for(var t,n=arguments.length,r=new Array(n),a=0;a<n;a++)r[a]=arguments[a];return(t=e.call.apply(e,[this].concat(r))||this).state={isLoaded:!1,instructions:null,learnerAssignment:null,labLauncher:null},t}r()(ProgrammingInstructions,e);var t=ProgrammingInstructions.prototype;return t.componentDidMount=function componentDidMount(){this.fetchData()},t.fetchData=function fetchData(){var e=this,t=this.props.itemMetadata,n=t.get("id"),r=t.get("course.id");if("programming"===t.getTypeName()){var a=Object(u.a)({itemMetadata:t,courseId:r,itemId:n});Promise.resolve(a).then(function(t){e.setState({isLoaded:!0,instructions:t})})}else{var o=Object(l.a)({itemId:n,courseId:r,courseSlug:t.get("course.slug")});Promise.resolve(o).then(function(t){var a;return"workspace"===t.submissionBuilderSchema.get("typeName")?Object(s.i)(r,n).then(function(n){e.setState({isLoaded:!0,instructions:t.submissionLearnerSchema.get("instructions"),learnerAssignment:t,labLauncher:n})}):Promise.resolve().then(function(){e.setState({isLoaded:!0,instructions:t.submissionLearnerSchema.get("instructions"),learnerAssignment:t})})}).catch(function(e){throw e})}},t.render=function render(){var e=this.props.itemMetadata,t=this.state,n=t.isLoaded,r=t.instructions,a=t.learnerAssignment,s=t.labLauncher;return o.a.createElement("div",{className:"rc-ProgrammingInstructions"},n?o.a.createElement(c.a,{instructions:r,itemMetadata:e,labLauncher:s,learnerAssignment:a}):o.a.createElement(i.a,null))},ProgrammingInstructions}(a.Component);e.default=d},WFBc:function(module,e,t){"use strict";function assert(e){var t=arguments.length>1&&void 0!==arguments[1]?arguments[1]:new Error;if(!e)throw"string"==typeof t?new Error(t):t;return e}t.d(e,"a",function(){return assert})},X6TH:function(module,e,t){"use strict";var n=t("S+eF"),r=t.n(n),a=t("sQ/U"),o=t("uJqh"),i=t("4b+W"),s=t("/KA1");e.a=function(e){return a.a.isAuthenticatedUser()?Object(i.a)(e).then(o.a).then(function(e){var t=e.elements[0];return new s.a(t,{parse:!0})}):r()({})}},Y7bb:function(module,exports,e){},"d/m/":function(module,e,t){"use strict";var n=t("VbXa"),r=t.n(n),a=t("q1tI"),o=t.n(a),i=t("sQ/U"),s=t("7mPg"),c=t("su8M"),u=t("BBzL"),l=t.n(u),d=function(e){function SleuthWorkspaceButton(){for(var t,n=arguments.length,r=new Array(n),a=0;a<n;a++)r[a]=arguments[a];return(t=e.call.apply(e,[this].concat(r))||this).getLaunchUrl=function(){var e=t.props,n=e.templateId,r=e.itemId,a=i.a.get().id;return t.workspacePromise||(t.workspacePromise=Object(s.a)(a,n)),t.workspacePromise.then(function(e){var t=e.id;return Object(s.b)(t,r)}).then(function(e){return e.url})},t.workspacePromise=void 0,t}var t;return r()(SleuthWorkspaceButton,e),SleuthWorkspaceButton.prototype.render=function render(){return o.a.createElement(c.a,{appName:l()("Sleuth Game"),getLaunchUrl:this.getLaunchUrl,trackingName:"sleuth_launch_button"})},SleuthWorkspaceButton}(a.Component);e.a=d},nfyY:function(module,e,t){"use strict";var n=t("VbXa"),r=t.n(n),a=t("VkAN"),o=t.n(a),i=t("AeFk"),s=t("q1tI"),c=t.n(s),u=t("wd/R"),l=t.n(u),d=t("17x9"),m=t.n(d),p=t("F/us"),g=t.n(p),b=t("WFBc"),f=t("kvW3"),h=t("sQ/U"),v=t("8Hdl"),O=t("6/Gu"),k=t("ZJgU"),j=t("jPyl"),I=t("aFpJ"),S=t("uJqh"),y=t("O+1n"),T=t("+2ZD"),A=t("LMJJ"),w=t("OAHX"),C=t("zlL2"),P=t("BBzL"),L=t.n(P),N=t("tOcQ"),E=t.n(N);function _templateObject2(){var e=o()(["\n    margin-right: ",";\n  "]);return _templateObject2=function _templateObject2(){return e},e}function _templateObject(){var e=o()(["\n    margin: "," 0;\n  "]);return _templateObject=function _templateObject(){return e},e}var z={gradedProgramming:A.a,ungradedProgramming:w.a},B={tokenContainer:function tokenContainer(e){return Object(i.c)(_templateObject(),e.spacing(24))},tokenValueContainer:function tokenValueContainer(e){return Object(i.c)(_templateObject2(),e.spacing(24))}},M=function(e){function ScriptTokenBox(){for(var t,n=arguments.length,r=new Array(n),a=0;a<n;a++)r[a]=arguments[a];return(t=e.call.apply(e,[this].concat(r))||this).state={agreementComplete:!1,currentTime:Date.now(),error:null,fullName:"",generatingToken:!1,isVerifying:!1,state:"ready",token:{}},t.onSubmitHonorCodeAgreement=function(){var e=t.state.fullName;t.setState({generatingToken:!0}),Object(y.a)().then(function(n){Object(y.b)(n,e).then(function(e){t.generateToken(e.get("id")),t.setState({isVerifying:!1,generatingToken:!1,agreementComplete:!1})})})},t.onTokenNotFound=function(){t.isGraded()?t.setState({state:"displaying"}):t.generateToken()},t.onTokenGenerated=function(){t.loadToken()},t.onFailedTokenGeneration=function(e){t.setState({state:"error",error:e})},t.onVerificationModalClose=function(){t.setState({isVerifying:!1})},t.onReceiveToken=function(e){t.setState({state:"displaying",token:e})},t.onHonorCodeAgreementComplete=function(e){t.setState({agreementComplete:!0,fullName:e})},t.onHonorCodeAgreementIncomplete=function(){t.setState({agreementComplete:!1})},t.updateCurrentTime=function(){t.setState({currentTime:Date.now()})},t.verifyAndGenerateToken=function(e){e&&e.preventDefault(),t.isGraded()?t.setState({isVerifying:!0}):t.generateToken()},t.api={},t.currentTimeInterval=null,t}r()(ScriptTokenBox,e);var t=ScriptTokenBox.prototype;return t.componentDidMount=function componentDidMount(){var e,t=this.props.itemMetadata.getTypeName();this.api=z[t],Object(b.a)(this.api,"Unknown assignment type: "+t),this.currentTimeInterval=window.setInterval(this.updateCurrentTime,1e3),this.loadToken()},t.componentWillUnmount=function componentWillUnmount(){this.currentTimeInterval&&clearInterval(this.currentTimeInterval)},t.loadToken=function loadToken(){this.setState({state:"getting"});var e=this.props.itemMetadata,t=e.get("id"),n=e.get("course").get("id"),r=e.get("course").get("slug");this.api.get({itemId:t,courseId:n,courseSlug:r}).then(S.a).then(function(e){return e.elements[0]}).then(this.onReceiveToken,this.onTokenNotFound).done()},t.generateToken=function generateToken(e){this.setState({state:"generating"});var t=this.props.itemMetadata,n=t.get("id"),r=t.get("course").get("id"),a=t.get("course").get("slug");this.api.newToken({itemId:n,courseId:r,courseSlug:a,verifiableId:e}).then(this.onTokenGenerated,this.onFailedTokenGeneration)},t.isGraded=function isGraded(){var e;return"gradedProgramming"===this.props.itemMetadata.getTypeName()},t.render=function render(){var e=this.state,t=e.state,n=e.token,r=e.currentTime,a=e.isVerifying,o=e.error,s=e.agreementComplete,c=e.generatingToken,u=n&&n.expiresAt-r<=0;return Object(i.d)(C.a,{instructions:Object(i.d)(f.b,{message:"Copy the token below and run the submission script included in the assignment download. When prompted, use your email address {userEmailAddress}.",userEmailAddress:Object(i.d)("b",null,h.a.get().email_address)})},Object(i.d)("div",{css:B.tokenContainer},g()(["getting","generating"]).contains(t)&&Object(i.d)(v.a,{variant:"h2semibold"},L()("Loading token...")),g()(["displaying"]).contains(t)&&Object(i.d)(O.a,{container:!0,alignItems:"center"},n&&Object(i.d)("div",{css:B.tokenValueContainer},(!n.expiresAt||!u)&&Object(i.d)(v.a,{variant:"h2semibold"},n.secret),n.expiresAt&&!u&&Object(i.d)(v.a,{variant:"body1"},Object(i.d)(f.b,{message:L()("This token expires in {expirationTime}"),expirationTime:l()(n.expiresAt).fromNow(!0)})),n.expiresAt&&u&&Object(i.d)(v.a,{variant:"body1"},L()("Your token expired"))),Object(i.d)(k.a,{variant:"ghost",size:"small",icon:Object(i.d)(j.a,{size:"small"}),iconPosition:"before",onClick:this.verifyAndGenerateToken},L()("Generate new token"))),g()(["error"]).contains(t)&&Object(i.d)("div",null,Object(i.d)(v.a,{variant:"body1"},Object(i.d)(f.b,{message:L()("There was an error getting your token: {error}"),error:o}))," ",Object(i.d)(k.a,{variant:"ghost",size:"small",icon:Object(i.d)(j.a,{size:"small"}),iconPosition:"before",onClick:this.verifyAndGenerateToken},L()("Click here to try to get it again")))),Object(i.d)(v.a,{variant:"body1"},L()("Your submission token is unique to you and should not be shared with anyone. You may submit as many times as you like.")),a&&Object(i.d)(T.a,{className:"honor-code-modal",modalName:"Programming Assignment Token",handleClose:this.onVerificationModalClose},Object(i.d)(v.a,{variant:"h3semibold"},L()("Honor Code")),Object(i.d)(I.a,{onAgreementComplete:this.onHonorCodeAgreementComplete,onAgreementIncomplete:this.onHonorCodeAgreementIncomplete,isShownInsideModal:!0}),Object(i.d)("div",{className:"align-right"},Object(i.d)(k.a,{variant:"primary",disabled:!s||c,onClick:this.onSubmitHonorCodeAgreement},c?L()("Loading..."):L()("Continue")))))},ScriptTokenBox}(c.a.Component);M.contextTypes={fluxibleContext:m.a.object.isRequired},e.a=M},su8M:function(module,e,t){"use strict";var n=t("lSNA"),r=t.n(n),a=t("q1tI"),o=t.n(a),i=t("w/1P"),s=t.n(i),c=t("uhOI"),u=t("gNwb"),l=t("/epD"),d=t("TSwX"),m=t("BBzL"),p=t.n(m),g=Object(u.e)({type:"BUTTON"})(d.a),b=function getApiButtonLabel(e,t,n){var a,o;return(a={},r()(a,c.a,n||(t?p()("Open #{appName}",{appName:t}):p()("Open"))),r()(a,c.c,p()("Opening...")),r()(a,c.d,t?p()("Opened #{appName}",{appName:t}):p()("Opened")),r()(a,c.b,t?p()("Error opening #{appName}",{appName:t}):p()("Error")),a)[e]},f=function WorkspaceButton(e){var t=e.className,n=e.getLaunchUrl,r=e.resetApiStatusDelay,a=e.appName,i=e.label,c=e.icon,u=e.variant,d=e.size,m=e.role,p=void 0===m?"button":m,f=e.trackingName,h=void 0===f?"workspace_launch_button":f;return o.a.createElement("div",{className:s()(t)},o.a.createElement(l.a,{getLaunchUrl:n,resetApiStatusDelay:r,render:function render(e){var t=e.apiStatus,n=e.onClick;return o.a.createElement(g,{label:b(t,a,i),variant:u,onClick:n,apiStatus:t,size:d,trackingName:h,iconPosition:"after",role:p},c)}}))};e.a=f},tOcQ:function(module,exports,e){var t=e("Y7bb"),n;"string"==typeof t&&(t=[[module.i,t,""]]);var r={transform:void 0},a=e("aET+")(t,r);t.locals&&(module.exports=t.locals)},teQO:function(module,e,t){"use strict";var n=t("VbXa"),r=t.n(n),a=t("VkAN"),o=t.n(a),i=t("AeFk"),s=t("q1tI"),c=t.n(s),u=t("sQ/U"),l=t("8Hdl"),d=t("6/Gu"),m=t("ZJgU"),p=t("jPyl"),g=t("4+Xa"),b=t("zlL2"),f=t("BBzL"),h=t.n(f);function _templateObject2(){var e=o()(["\n    margin-right: ",";\n  "]);return _templateObject2=function _templateObject2(){return e},e}function _templateObject(){var e=o()(["\n    margin: "," 0;\n  "]);return _templateObject=function _templateObject(){return e},e}var v={tokenContainer:function tokenContainer(e){return Object(i.c)(_templateObject(),e.spacing(24))},tokenValueContainer:function tokenValueContainer(e){return Object(i.c)(_templateObject2(),e.spacing(24))}},O=function(e){function TokenBox(){for(var t,n=arguments.length,r=new Array(n),a=0;a<n;a++)r[a]=arguments[a];return(t=e.call.apply(e,[this].concat(r))||this).state={secret:"",status:"empty"},t.handleClickGenerateToken=function(e){e.preventDefault(),t.generateToken()},t.handleClickGetToken=function(e){e.preventDefault(),t.getToken()},t}r()(TokenBox,e);var t=TokenBox.prototype;return t.componentDidMount=function componentDidMount(){this.getToken()},t.getToken=function getToken(){var e=this,t=this.props.itemMetadata;return this.setState({status:"getting"}),g.a.get({itemId:t.get("id"),courseId:t.get("course.id"),courseSlug:t.get("course.slug")}).then(function(t){var n=t.elements[0];e.setState({secret:n.token||n.secret,status:"displaying"})},function(t){return 404===t.status?e.generateToken():e.setState({status:"error"})}).done()},t.generateToken=function generateToken(){var e=this,t=this.props.itemMetadata;return this.setState({status:"generating"}),g.a.newToken({itemId:t.get("id"),courseId:t.get("course.id"),courseSlug:t.get("course.slug")}).then(function(t){var n=t.body.elements[0];e.setState({secret:n.token||n.secret,status:"displaying"})}).done()},t.render=function render(){var e=this.state,t=e.secret,n=e.status;return Object(i.d)(b.a,{instructions:Object(i.d)("div",null,h()("Copy the token below and run the submission script included in the assignment download. When prompted, use your email address "),Object(i.d)("b",null,u.a.get().email_address),".")},Object(i.d)("div",{css:v.tokenContainer},"empty"===n&&Object(i.d)(l.a,{variant:"body1"},h()("no token")),"getting"===n&&Object(i.d)(l.a,{variant:"body1"},h()("Getting token...")),"generating"===n&&Object(i.d)(l.a,{variant:"body1"},h()("Generating token...")),"displaying"===n&&Object(i.d)(d.a,{container:!0,alignItems:"center"},Object(i.d)("div",{css:v.tokenValueContainer},Object(i.d)(l.a,{variant:"h2semibold"},t)),Object(i.d)(l.a,{variant:"body1"},Object(i.d)("button",{type:"button",onClick:this.handleClickGenerateToken},h()("Generate new token")))),"error"===n&&Object(i.d)(d.a,{container:!0,alignItems:"center"},Object(i.d)("div",{css:v.tokenValueContainer},Object(i.d)(l.a,{variant:"body1"},h()("There was an error getting your token:"))),Object(i.d)(m.a,{variant:"ghost",size:"small",icon:Object(i.d)(p.a,{size:"small"}),iconPosition:"before",onClick:this.handleClickGetToken},h()("Click here to try to get it again")))),Object(i.d)(l.a,{variant:"body1"},h()("Your submission token is unique to you and should not be shared with anyone. You may submit as many times as you like.")))},TokenBox}(c.a.Component);e.a=O},uMx8:function(module,e,t){"use strict";t.d(e,"a",function(){return i}),t.d(e,"b",function(){return s});var n=t("lSNA"),r=t.n(n),a=t("KMW/");function ownKeys(e,t){var n=Object.keys(e);if(Object.getOwnPropertySymbols){var r=Object.getOwnPropertySymbols(e);t&&(r=r.filter(function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable})),n.push.apply(n,r)}return n}function _objectSpread(e){for(var t=1;t<arguments.length;t++){var n=null!=arguments[t]?arguments[t]:{};t%2?ownKeys(Object(n),!0).forEach(function(t){r()(e,t,n[t])}):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(n)):ownKeys(Object(n)).forEach(function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(n,t))})}return e}var o={templateId:"IIknfCCpTv2JJ3wgqU79KA"},i=function getSleuthConfig(e,t){var n,r=(a.a.get("Workspaces","sleuthAssignments")||[]).find(function(n){return n.courseId===e&&n.itemId===t});return r?_objectSpread(_objectSpread({},o),r):null},s=function isSleuthAssignment(e,t){return!!i(e,t)}},"um/3":function(module,e,t){"use strict";var n=t("q1tI"),r=t.n(n),a=t("yizN"),o=Object(a.b)("ErrorIcon",{ltr:{small:function small(e){return r.a.createElement(r.a.Fragment,null,r.a.createElement("path",{fillRule:"evenodd",clipRule:"evenodd",d:"M7.374.689a1.16 1.16 0 011.676.482l6.301 12.403a1.301 1.301 0 01-.981 1.922l-.03.004H1.66l-.03-.004a1.3 1.3 0 01-.981-1.922L6.95 1.171A1.16 1.16 0 017.374.69zm.026.701l.446.226L1.53 14.047l-.005.01a.3.3 0 00.202.443h12.546a.3.3 0 00.203-.443l-.006-.01-6.32-12.44-.004-.009a.16.16 0 00-.291 0L7.4 1.39z",fill:"currentColor"}),r.a.createElement("path",{d:"M8 13a.86.86 0 100-1.72A.86.86 0 008 13z",fill:"currentColor"}),r.a.createElement("path",{fillRule:"evenodd",clipRule:"evenodd",d:"M7.5 10V6h1v4h-1z",fill:"currentColor"}))},medium:function medium(e){return r.a.createElement(r.a.Fragment,null,r.a.createElement("path",{fillRule:"evenodd",clipRule:"evenodd",d:"M9.31 1.701a1.25 1.25 0 011.832.536l7.188 14.166a1.41 1.41 0 01-1.061 2.094l-.03.003H2.76l-.029-.003a1.41 1.41 0 01-1.061-2.094L8.858 2.237A1.25 1.25 0 019.31 1.7zm0 .749l.446.226L2.55 16.88l-.007.012a.41.41 0 00.282.609h14.35a.41.41 0 00.282-.61l-.007-.011L10.237 2.66l-.007-.015a.25.25 0 00-.46 0l-.46-.196z",fill:"currentColor"}),r.a.createElement("path",{d:"M10 15.86A.93.93 0 1010 14a.93.93 0 000 1.86z",fill:"currentColor"}),r.a.createElement("path",{fillRule:"evenodd",clipRule:"evenodd",d:"M10 14.86a.07.07 0 100 .14.07.07 0 000-.14zm.93.07a.93.93 0 11-1.86 0 .93.93 0 011.86 0zM9.5 12.47V7h1v5.47h-1z",fill:"currentColor"}))},large:function large(e){return r.a.createElement(r.a.Fragment,null,r.a.createElement("path",{fillRule:"evenodd",clipRule:"evenodd",d:"M11.146 1.7a1.44 1.44 0 012.172.659l8.984 17.716a1.64 1.64 0 01-1.243 2.422l-.03.003H2.91l-.032-.004a1.64 1.64 0 01-1.229-2.42l8.983-17.717a1.44 1.44 0 01.515-.66zm-.056.86l.446.226-9.005 17.76-.005.01a.64.64 0 00.45.944h17.99a.64.64 0 00.458-.945l-.005-.01-9.02-17.787-.01-.03a.44.44 0 00-.828 0l-.471-.168z",fill:"currentColor"}),r.a.createElement("path",{d:"M11.95 19a.93.93 0 100-1.86.93.93 0 000 1.86z",fill:"currentColor"}),r.a.createElement("path",{fillRule:"evenodd",clipRule:"evenodd",d:"M11.45 15V8h1v7h-1z",fill:"currentColor"}))}}},!1);e.a=o},zlL2:function(module,e,t){"use strict";var n=t("VkAN"),r=t.n(n),a=t("AeFk"),o=t("q1tI"),i=t.n(o),s=t("763+"),c=t("8Hdl"),u=t("BBzL"),l=t.n(u);function _templateObject2(){var e=r()(["\n    margin-bottom: ",";\n  "]);return _templateObject2=function _templateObject2(){return e},e}function _templateObject(){var e=r()(["\n    border: 1px solid ",";\n    border-radius: ",";\n    padding: ",";\n  "]);return _templateObject=function _templateObject(){return e},e}var d=function container(e){return Object(a.c)(_templateObject(),e.palette.gray[500],e.spacing(4),e.spacing(16))},m=function title(e){return Object(a.c)(_templateObject2(),e.spacing(8))},p=function SubmissionInstructionsBox(e){var t=e.instructions,n=e.title,r=e.children,o=e.className,i=Object(s.a)();return Object(a.d)("div",{css:d(i),className:o},Object(a.d)(c.a,{variant:"h3semibold",css:m(i)},n||l()("How to submit")),Object(a.d)(c.a,{variant:"body1"},t),r)};e.a=p}}]);
//# sourceMappingURL=88.5ee7c9d793be1ae18bf9.js.map