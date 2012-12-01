/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: luma(stubma@gmail.com)
 *
 * For all entities this program is free software; you can redistribute
 * it and/or modify it under the terms of the 'WiEngine' license with
 * the additional provision that 'WiEngine' must be credited in a manner
 * that can be be observed by end users, for example, in the credits or during
 * start up. (please find WiEngine logo in sdk's logo folder)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef __wyAFCSprite_h__
#define __wyAFCSprite_h__

#include "wyNode.h"
#include "wyArray.h"
#include "WiEngine-Classes.h"

/**
 * Callback interface of \link wyAFCSprite wyAFCSprite\endlink
 */
class WIENGINE_API wyAFCSpriteCallback {
public:
	/**
	 * Invoked when frame changed
	 *
	 * @param sprite \link wyAFCSprite wyAFCSprite\endlink
	 */
	virtual void onAFCSpriteAnimationFrameChanged(wyAFCSprite* sprite) = 0;

	/**
	 * Invoked when animation ended
	 *
	 * @param sprite \link wyAFCSprite wyAFCSprite\endlink
	 */
	virtual void onAFCSpriteAnimationEnded(wyAFCSprite* sprite) = 0;
};

/**
 * @class wyAFCSprite
 *
 * \par
 * AFC means Animation, Frame, Clip and it is an architecture of frame animation. That is
 * to say, animation consists of frame and frame consists of fragment. This architecture
 * is common and many animation editors support it. Purpose of \link wyAFCSprite wyAFCSprite\endlink
 * is encapsulating the common logic for all AFC editors.
 *
 * \par
 * For other editors, terms may differ but meaning is similar. For example:
 * \li Motion Welder: it calls AFC
 * \li SpriteX: it calls AFT: Action, Frame, Tile
 * \li Arctic & AuroraGT: it calls AFM: Animation, Frame, Module
 * Motion Welder is first animation editor supported by WiEngine, so we use AFC as a souvenir.
 *
 * \par
 * Some complex transformation is not supported, such as clip rotation and animation rotation.
 * Those features are not important.
 *
 * \par
 * Duration time of frame has two measurement: by time or by tick. Some editor, likes Motion Welder, Arctic,
 * etc. uses an integer as frame duration. The integer is a tick count, not time, so animation will be faster
 * if device has higher frame rate. In \link wyAFCSprite wyAFCSprite\endlink, there is an unit interval can be
 * set and if it is not zero, the final duration time will be the result of multiply tick and unit interval.
 * By default it is zero and it means using tick directly.
 *
 * \par
 * \link wyAFCSprite wyAFCSprite\endlink subclass has a zero size so you can't perform collision detection
 * based on node size. \link wyAFCSprite wyAFCSprite\endlink provides \c getFrameRect methods to return a
 * minimum rectangle containing all clips of current frame
 */
class WIENGINE_API wyAFCSprite : public wyNode {
protected:
	/// mesh reference cache
	vector<wyMeshRef*>* m_meshRefCache;

	/// \link wySpriteEx wySpriteEx\endlink list for every clip
	wyArray* m_spriteList;

	/// List of \link wySpriteBatchNode wySpriteBatchNode\endlink
	wyArray* m_sheetList;

	/// List of \link wyAFCClipMapping wyAFCClipMapping\endlink
	wyArray* m_mappingList;

	/// data of current AFC animation
	wyAFCAnimation* m_animationData;

	/// Index of current animation
	int m_curAnimationIndex;

	/// Index of current frame
	int m_curFrame;

	/// frame count of current animation
	int m_numOfFrame;

	/// duration time of current frame
	float m_frameDuration;

	/// true means \c m_frameDuration is a tick value, not time
	bool m_isTickDelay;

	/// true means use tick mode to play animation, default is false
	bool m_forceTickMode;

	/// accumulated offset till to current frame
	wyPoint m_frameOffset;

	/**
	 * true indicating ignore frame offset, default is false.
	 */
	bool m_ignoreFrameOffset;

	/// Time elapsed of current frame, should switch to next frame if it is larger than \c m_frameDuration
	float m_elapsed;

	/**
	 * Unit interval of animation frame. Default unit interval is 0 so it means don't use unit
	 * interval.
	 */
	float m_unitInterval;

	/// reverse playing flag
	bool m_isReverse;

	/**
	 * -1 means loop forever
	 * 0 means don't loop
	 * > 0 means loop count
	 */
	int m_loop;

	/// a helper variable of looping
	int m_tmpLoop;

	/// true means animation is over
	bool m_isAnimationEnded;

	/// true means animation is paused
	bool m_paused;

	/// If set to true, frame rect will be drawn, for debug purpose
	bool m_debugDrawFrameRect;

	/// If set to true, collision rect will be drawn, for debug purpose
	bool m_debugDrawCollisionRect;

	/// true means x axis should be flipped
	bool m_flipX;

	/// true means y axis should be flipped
	bool m_flipY;

	/// callback
	wyAFCSpriteCallback* m_callback;

private:
	static bool releaseObject(wyArray* arr, void* ptr, int index, void* data);

	void invokeOnAFCAnimationFrameChanged();
	void invokeOnAFCAnimationEnded();

protected:
	wyAFCSprite();

	/**
	 * Set animation data
	 *
	 * @param data \link wyAFCAnimation wyAFCAnimation\endlink
	 */
	void setAnimationData(wyAFCAnimation* data);

	/// Create sprite pool for current animation
	void initSpriteFromAnimationData();

	/// Initialize frame offset at start of animation
	void initFrameOffset();

	/**
	 * Adjust frame offset for a frame
	 *
	 * @param frameData \link wyAFCFrame wyAFCFrame\endlink
	 */
	void adjustFrameOffset(wyAFCFrame* frameData);

	/// get a mesh reference from cache or create a new one
	wyMeshRef* getMeshRef();

	/// refill mesh ref cache from current render pair list, and current render pair list will be cleared
	void refillRefCache();

public:
	virtual ~wyAFCSprite();

	/// @see wyNode::updateMesh
	virtual void updateMesh();

	/// @see wyNode::updateMeshColor
	virtual void updateMeshColor();

	/// @see wyNode::addChild(wyNode*, int, int)
	virtual void addChild(wyNode* child, int z, int tag);

	/**
	 * Get file data object. A file data is a top level object, it may contain
	 * more than one animation data
	 *
	 * \note
	 * Values in file data is not scaled based on density
	 *
	 * @return \link wyAFCFileData wyAFCFileData\endlink object
	 */
	virtual wyAFCFileData* getFileData() = 0;

	/**
	 * Get animation at specified index
	 *
	 * @param index animation index
	 * @param mapping clip mapping, default is NULL
	 */
	virtual wyAFCAnimation* getAnimationAt(int index, wyAFCClipMapping* mapping = NULL) = 0;

	/**
	 * Get animation count
	 *
	 * @return animation count
	 */
	virtual int getAnimationCount() = 0;

	/**
	 * Get image count
	 *
	 * @return image count
	 */
	virtual int getImageCount() = 0;

	/**
	 * Play an animation, it will immediately end current animation (if has)
	 *
	 * \note
	 * Currently, clip mapping doesn't support SpriteX 2011 and Motion Welder
	 *
	 * @param index index of animation
	 * @param mapping clip mapping, default is NULL. A clip mapping must be added
	 * 		to \link wyAFCSprite wyAFCSprite\endlink before use it in \c playAnimation
	 */
	void playAnimation(int index, wyAFCClipMapping* mapping = NULL);

	/**
	 * Play an animation and apply a clip mapping to it
	 *
	 * @param index index of animation
	 * @param mappingTag tag of clip mapping
	 */
	void playAnimation(int index, int mappingTag);

	/**
	 * Set current frame index
	 *
	 * @param index frame index
	 */
	void setFrameIndex(int index);

	/**
	 * Update animation by a delta time. Must be called continuously and usually you
	 * can schedule a timer to invoke it.
	 *
	 * @param delta time from last update
	 */
	void tick(float delta);

	/**
	 * Set ignore frame offset when rendering or not
	 *
	 * \note
	 * Not all editor support it. Generally speaking, if editor support frame
	 * offset, then clip position must be relative to frame, not animation. For now,
	 * Motion Welder and Arctic support it.
	 *
	 * @param flag true means ignore frame offset
	 */
	void setIgnoreFrameOffset(bool flag) { m_ignoreFrameOffset = flag; }

	/**
	 * is frame offset ignored? The flag only disable frame offset when rendering,
	 * it doesn't forbid you getting frame offset.
	 *
	 * @return true means frame offset is ignored
	 */
	bool isIgnoreFrameOffset() { return m_ignoreFrameOffset; }

	/**
	 * Get current frame offset. Frame offset is the delta value between current frame and
	 * first frame.
	 *
	 * @return current frame offset
	 */
	wyPoint getFrameOffset() { return m_frameOffset; }

	/**
	 * Set animation event callback
	 *
	 * @param callback \link wyAFCSpriteCallback wyAFCSpriteCallback\endlink, if NULL, means clear callback
	 */
	void setAFCSpriteCallback(wyAFCSpriteCallback* callback) { m_callback = callback; }

	/**
	 * Get current animation index. Index starts from 0.
	 *
	 * @return current animation index
	 */
	int getCurrentAnimationIndex() { return m_curAnimationIndex; }

	/**
	 * Get current frame index
	 *
	 * @return current frame index
	 */
	int getCurrentFrame() { return m_curFrame; }

	/**
	 * Get frame count of current animation
	 *
	 * @return frame count of current animation
	 */
	int getFrameCount() { return m_numOfFrame; }

	/**
	 * is reverse playing?
	 *
	 * @return true means reverse playing
	 */
	bool isReverse() { return m_isReverse; }

	/**
	 * Set reverse playing or not
	 *
	 * @param flag true means reverse playing
	 */
	void setReverse(bool flag) { m_isReverse = flag; }

	/**
	 * Get loop count
	 *
	 * @return -1 means loop forever, 0 means no loop, larger than 0 means loop times
	 */
	int getLoopCount() { return m_loop; }

	/**
	 * Set loop count
	 *
	 * @param loop loop count, -1 means loop forever, 0 means no loop, larger than 0 means loop times
	 */
	void setLoopCount(int loop);

	/**
	 * is animation ended
	 *
	 * @return true means animation is ended
	 */
	bool isAnimationEnded() { return m_isAnimationEnded; }

	/**
	 * is animation flipped in x axis?
	 *
	 * @return true means animation is flipped in x axis
	 */
	bool isFlipX() { return m_flipX; }

	/**
	 * Make animation flipped in x axis or not
	 *
	 * @param flipX true means animation should be flipped in x axis
	 */
	void setFlipX(bool flipX);

	/**
	 * is animation flipped in y axis?
	 *
	 * @return true means animation is flipped in y axis
	 */
	bool isFlipY() { return m_flipY; }

	/**
	 * Make animation flipped in y axis or not
	 *
	 * @param flipY true means animation should be flipped in y axis
	 */
	void setFlipY(bool flipY);

	/**
	 * Pause animation or not
	 *
	 * @param flag true means pause animation
	 */
	void setPaused(bool flag) { m_paused = flag; }

	/**
	 * is animation paused
	 *
	 * @return true means paused
	 */
	bool isPaused() { return m_paused; }

	/**
	 * Get data of current animation
	 *
	 * \note
	 * Returned info is auto scaled by WiEngine on the basis of density
	 *
	 * @return \link wyAFCAnimation wyAFCAnimation\endlink
	 */
	wyAFCAnimation* getCurrentAnimationData() { return m_animationData; }

	/**
	 * Get unit interval time
	 *
	 * @return unit interval time
	 */
	float getUnitInterval() { return m_unitInterval; }

	/**
	 * Set unit interval time. If value is not zero and animation editor uses tick value, then
	 * final duration time is result of multiply unit interval and tick value
	 *
	 * @param interval unit interval time
	 */
	void setUnitInterval(float interval);

	/**
	 * Is animation played in tick mode? That means frame duration is measured by drawing frame and
	 * its speed can be controlled by unit interval
	 *
	 * @return true means animation is played in tick mode
	 */
	bool isForceTickMode() { return m_forceTickMode; }

	/**
	 * Set use tick mode or time mode to play animation
	 *
	 * @param flag true means use tick mode
	 */
	void setForceTickMode(bool flag) { m_forceTickMode = flag; }

	/**
	 * Get total number of collision rectangle in current frame
	 */
	int getCollisionRectCount();

	/**
	 * Get collision rect of current frame, in node coordinates
	 *
	 * @param index index of collision rect
	 * @return \link wyRect wyRect\endlink, if no collision rect in current frame or
	 * 		\c index is invalid, return a zero rect
	 */
	wyRect getCollisionRect(int index);

	/**
	 * Get collision rect of current frame, in parent node coordinates. If node has rotation, then
	 * returned rectangle may be a circumscribed rectangle
	 *
	 * @param index index of collision rect
	 * @return \link wyRect wyRect\endlink, if no collision rect in current frame or
	 * 		\c index is invalid, return a zero rect
	 */
	wyRect getCollisionRectRelativeToParent(int index);

	/**
	 * Get collision rect of current frame, in global coordinates. If node has rotation, then
	 * returned rectangle may be a circumscribed rectangle
	 *
	 * @param index index of collision rect
	 * @return \link wyRect wyRect\endlink, if no collision rect in current frame or
	 * 		\c index is invalid, return a zero rect
	 */
	wyRect getCollisionRectRelativeToWorld(int index);

	/**
	 * Get current frame bound relative to sprite node. It returns a minimum rectangle which
	 * contains all clips
	 *
	 * @return minimum rectangle which contains all clips, relative to node coordinates
	 */
	wyRect getFrameRect();

	/**
	 * Get current frame bound relative to parent node. It returns a minimum rectangle
	 * which contains all clips
	 *
	 * @return minimum rectangle which contains all clips, relative to parent node
	 * 		coordinates
	 */
	wyRect getFrameRectRelativeToParent();

	/**
	 * Get current frame bound relative to world. It returns a minimum rectangle
	 * which contains all clips
	 *
	 * @return minimum rectangle which contains all clips, relative to global coordinates
	 */
	wyRect getFrameRectRelativeToWorld();

	/**
	 * Set debug draw flag of drawing frame rect
	 *
	 * @param flag true means frame rect will be drawn, for debug purpose
	 */
	void setDebugDrawFrameRect(bool flag) { m_debugDrawFrameRect = flag; }

	/**
	 * Set debug draw flag of drawing collision rect
	 *
	 * @param flag true means collision rect will be drawn, for debug purpose
	 */
	void setDebugDrawCollisionRect(bool flag) { m_debugDrawCollisionRect = flag; }

	/**
	 * Add a clip mapping to this sprite, which can be used later in \c playAnimation
	 *
	 * @param mapping \link wyAFCClipMapping wyAFCClipMapping\endlink
	 */
	void addClipMapping(wyAFCClipMapping* mapping);

	/**
	 * Remove a clip mapping by its tag
	 *
	 * @param tag tag of clip mapping
	 */
	void removeClipMappingByTag(int tag);

	/**
	 * Get a clip mapping by tag
	 *
	 * @param tag tag of clip mapping
	 * @return clip mapping or NULL if not found
	 */
	wyAFCClipMapping* getClipMappingByTag(int tag);

	/**
	 * Replace current textures with another set of textures. You must ensure
	 * the new set of textures has same size and quantity as old set.
	 *
	 * @param tex texture 1, other textures can follow it and NULL ends
	 */
	void replaceTextures(wyTexture2D* tex, ...);

	/**
	 * Replace current textures with another set of textures. You must ensure
	 * the new set of textures has same size and quantity as old set. Texture
	 * can be set to NULL.
	 *
	 * @param tex texture list, can have NULL in the list
	 * @param count texture count in \c tex
	 */
	void replaceTextures(wyTexture2D** tex, int count);
};

#endif // __wyAFCSprite_h__
